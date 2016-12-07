#!/usr/bin/python
#
# Unit Summariser
# Copyright (C) 2005-2006 Daniel Aleksandrow
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#

import sys
import os
import fnmatch
import string
import unicodedata
from xml.dom.minidom import *

units = list()
outputdoc = Document()
columns_wanted = list()
column_descriptions = list()
column_types = list()
rows_wanted = list()
csvfiles = list()

# 0 - don't process the files, 1 - process but don't format, 2 - full works.

process = 1

# Look at default units and default columns
#units+= ['llama','gawain','lancelot','thrud','redeemer']# For the .csv format.
#columns_wanted+= ['Name','Combat_Role','Mass']# For the .csv format.

csvfiles = ['units.csv','units/units.csv','data4.x/units/units.csv','../units/units.csv','../../data4.x/units/unitx.csv']

HELPTEXT = string.join(["Usage: unit_summariser.py [options] file [units] [columns]",
"  where options are:",
"      -help, which displays this message",
"      -fullprocess, which enables pretty printing for summary use",
"  ",
"  where file is the optional path to the units.csv file to be used.",
"  ",
"  where units consists of the argument -ships, followed by a unit list.",
"    (ie -ships llama redeemer thrud)",
"  ",
"  where columns consists of the argument -columns, followed by a column list.",
"    (ie -columns Name Combat_Role Mass)",
"",
"The Unit Summariser is a tool for units.csv viewing.",
"For updates and additional information, see",
"    the Vega Strike home page at http://vegastrike.sourceforge.net/"],"\n")

#----------------
# Parsing Functions
#----------------
def parseArgs(argstoparse):
    global HELPTEXT
    global process
    global units
    global columns_wanted
    global csvfiles
    argstoparse.pop(0)
    while len(argstoparse):
        if argstoparse[0] in ['-help','--help']:
            print HELPTEXT
            process = 0
            argstoparse.pop(0)
            pass
        elif argstoparse[0] == '-fullprocess':
            process = 2
            argstoparse.pop(0)
            pass
        elif argstoparse[0] == '-ships':
            argstoparse.pop(0)
            while len(argstoparse):
                if argstoparse[0] == '-columns':
                    break
                units.append(argstoparse.pop(0))
            pass
        elif argstoparse[0] == '-columns':
            argstoparse.pop(0)
            while len(argstoparse):
                if argstoparse[0] == '-ships':
                    break
                columns_wanted.append(argstoparse.pop(0))
            pass
        else:# Assume the arg must be a file.
            csvfiles = [argstoparse.pop(0)]+csvfiles


def splitLine(row):
    """This function made possible by the tears of a thousand nerds."""
    delim = ','
    qual = '"'
    length = len(row)
    inside = False
    word = str()
    split_row = list()
    for i in range(length):
        if (row[i] == delim and not inside):
            split_row.append(word)
            word = str()
        elif (inside and row[i] == qual and row[i+1] == qual):
            word+= qual
            i+=1
        elif row[i] == qual:
            inside = not inside
        else:
            word+= row[i]
    split_row.append(word)
    return split_row

#----------------
# Formatting Functions
#----------------

def formatCell(document, description, cell):
    global process
    if process < 2:
        return [document.createTextNode(cell)]
    if description == "Mounts":
        return formatMounts(document, cell)
    else:
        return [document.createTextNode(cell)]
        

def formatMounts(document, cell):
# {type(string);ammo(int);volume(meters);SIZE(string);x(meters);y(meters);z(meters);xyscale(meters);zscale(meters);forex(meters);forey(meters);forez(meters);upx(meters);upy(meters);upz(meters);functionality(percentage);maxfunctionality(percentage)}
    output_nodes = list()
    mounts = cell[1:len(cell)-1].split("}{")
    for mount in mounts:
        mount = mount.split(";")
        if mount[0] == "":
            mount[0] = "None"
        if mount[1] == "":
            mount[1] = unicodedata.lookup('infinity')
        output_nodes.append(document.createTextNode(mount[0] + "  :  " + mount[1] + "  :  " + mount[3]))
        output_nodes.append(document.createElement("br"))
    return output_nodes[:len(output_nodes)-1]
    
    
#----------------
# The start of the script
#----------------

arg = sys.argv

srcpath = os.curdir
if len(arg) > 1:
    parseArgs(arg)

if process:
    print 'Opening units.csv ... ',

success = False
for loc in csvfiles:
    if not process:
        break
    try:
        csv = file(os.curdir+'/'+loc)
        success = True
        print 'done.'

        print 'Importing the rows ... ',
        column_descriptions = splitLine(csv.readline())
        column_types = splitLine(csv.readline())
        
        while 1:
            wantrow = False
            row = csv.readline()# Go through each row until there are none to get.
            if not row:
                break
            if len(units) == 0:
                if row.find(',') == 0 or row.find('"",') == 0:
                    wantrow = False
                else:
                    wantrow = True
            for unit in units:
                if row.find('"'+unit+'",') == 0:# If it's one of the units we want, yay!
                    wantrow = True
                    break
            if wantrow:
                rows_wanted.append(splitLine(row))
        csv.close()
        print 'done.'

        
    except:
        pass

if success and process:
    
    print 'Processing the rows ... ',
    indicies = [0]
    sep_descriptions = [""]# Start with an unlabelled first column.
    sep_types = list()
    sep_rows = list()
    for i in range(1,len(column_descriptions)):
        if column_descriptions[i] in columns_wanted or len(columns_wanted) == 0:
            indicies.append(i)
            sep_descriptions.append(column_descriptions[i])
    for index in indicies:
        sep_types.append(column_types[index])
    for row in rows_wanted:
        new_row = list()
        for index in indicies:
            new_row.append(row[index])
        sep_rows.append(new_row)
    print 'done.'
    
    print 'Formatting the output ... ',# FIXME: Insert formatter here
    outputdoc.appendChild(outputdoc.createElement('html'))
    head = outputdoc.createElement('head')
    css = outputdoc.createElement('link')
    css.setAttribute('rel','stylesheet')
    css.setAttribute('type','text/css')
    css.setAttribute('href','unit_summariser.css')
    title = outputdoc.createElement('title')
    title.appendChild(outputdoc.createTextNode('Unit Stats Summary'))
    tablesort1 = outputdoc.createElement('script')
    tablesort1.setAttribute('type','text/javascript')
    tablesort1.setAttribute('src','res/common.js')
    tablesort1.appendChild(outputdoc.createTextNode(""))#For IE compat.
    tablesort2 = outputdoc.createElement('script')
    tablesort2.setAttribute('type','text/javascript')
    tablesort2.setAttribute('src','res/css.js')
    tablesort2.appendChild(outputdoc.createTextNode(""))#For IE compat.
    tablesort3 = outputdoc.createElement('script')
    tablesort3.setAttribute('type','text/javascript')
    tablesort3.setAttribute('src','res/standardista-table-sorting.js')
    tablesort3.appendChild(outputdoc.createTextNode(""))#For IE compat.
    head.appendChild(css)
    head.appendChild(title)
    head.appendChild(tablesort1)
    head.appendChild(tablesort2)
    head.appendChild(tablesort3)
    outputdoc.firstChild.appendChild(head)
    
    body = outputdoc.createElement('body')    
    table = outputdoc.createElement('table')
    table.setAttribute('class','sortable listview')
    table.setAttribute('cellspacing', '0')
    thead = outputdoc.createElement('thead')
    tr = outputdoc.createElement('tr')
    for description in sep_descriptions:
        td = outputdoc.createElement('td')
        td.appendChild(outputdoc.createTextNode(description))
        tr.appendChild(td)
    thead.appendChild(tr)
    tr = outputdoc.createElement('tr')
    tr.setAttribute('class','sub')
    for type in sep_types:
        td = outputdoc.createElement('td')
        td.appendChild(outputdoc.createTextNode(type))
        td.setAttribute('class','sub')
        tr.appendChild(td)
    thead.appendChild(tr)
    table.appendChild(thead)
    tbody = outputdoc.createElement('tbody')
    odd = True
    for row in sep_rows:
        tr = outputdoc.createElement('tr')
        if odd:
            tr.setAttribute('class','odd')
        odd = not odd
        for i in range(len(row)):
            column = row[i]
            td = outputdoc.createElement('td')
            formattedcells = formatCell(outputdoc, sep_descriptions[i],column)
            for cell in formattedcells:
                td.appendChild(cell)
            tr.appendChild(td)
        tbody.appendChild(tr)
    table.appendChild(tbody)
    body.appendChild(table)
    outputdoc.firstChild.appendChild(body)
    print 'done.'

    print 'Writing the output ... ',
    xhtml = open('unit_summary.html','w')
    xhtml.write(outputdoc.toprettyxml('    ','\n',"UTF-8"))
    xhtml.close()
    print 'done.'

