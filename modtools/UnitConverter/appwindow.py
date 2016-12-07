#---------------------------------------------------------------------------------
# A Tkinter application frame with menu buttons.
# Copyright (C) 2008 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 3
# of the License, or (at your option) any later version.
#
# Description: Provides a frame widget with menu button
# Author: pyramid
# Version: 2008-09-14 | v0.25
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------

from Tkinter import *

class AppWindow:

	# receives master widget reference and orientation
	def __init__(self, master, side=LEFT):
          self.activeframe = None
          self.count = 0
          self.choice = IntVar(0)
          # allows the TOP and BOTTOM
          # radiobuttons' positioning.
          if side in (TOP, BOTTOM):
                  self.side = LEFT
          else:
                  self.side = TOP
          # creates window frame structure
          self.rb_fr = Frame(master, borderwidth=2, relief=RIDGE, bg="#BFB8FE")
          #self.rb_fr = AppFrame(master, borderwidth=2, relief=RIDGE, bg="#BFB8FE")
          #self.rb_fr = AppWinFrame(master)
          self.rb_fr.pack(side=side, fill=BOTH)
          self.screen_fr = Frame(master, borderwidth=2, relief=RIDGE, bg="#BFB8FE")
          #self.screen_fr = AppFrame(master)
          self.screen_fr.pack(fill=BOTH)

	# return a master frame reference for the external frames (screens)
	def __call__(self):
		return self.screen_fr
	
	# add a new frame (screen) to the (bottom/left of the) window
	def add_screen(self, fr, title):
          b = Radiobutton(self.rb_fr, text=title, indicatoron=0, \
                  variable=self.choice, value=self.count, \
                  command=lambda: self.display(fr))
          b.pack(fill=BOTH, side=self.side)
          # ensures the first frame will be
          # the first selected/enabled
          if not self.activeframe:
                  fr.pack(fill=BOTH, expand=1)
                  self.activeframe = fr
          self.count += 1
          # returns a reference to the newly created
          # radiobutton (allowing its configuration/destruction)         
          return b
	
	# hides the former active frame and shows 
	# another one, keeping its reference
	def display(self, fr):
          self.activeframe.forget()
          fr.pack(fill=BOTH, expand=1)
          #fr.update_idletasks()
          #fr.config(scrollregion=fr.bbox("all"))
          self.activeframe = fr

class AutoScrollbar(Scrollbar):
    # a scrollbar that hides itself if it's not needed.  only
    # works if you use the grid geometry manager.
    def set(self, lo, hi):
        if float(lo) <= 0.0 and float(hi) >= 1.0:
            # grid_remove is currently missing from Tkinter!
            self.tk.call("grid", "remove", self)
        else:
            self.grid()
        Scrollbar.set(self, lo, hi)
    def pack(self, **kw):
        raise TclError, "cannot use pack with this widget"
    def place(self, **kw):
        raise TclError, "cannot use place with this widget"

def AppWinFrame(master):
  # auto scrolls
  """
  vscrollbar = Scrollbar(master)
  vscrollbar.grid(row=0, column=1, sticky=N+S)
  hscrollbar = Scrollbar(master, orient=HORIZONTAL)
  hscrollbar.grid(row=1, column=0, sticky=E+W)
  canvas = Canvas(master, 
                  yscrollcommand=vscrollbar.set, 
                  xscrollcommand=hscrollbar.set, bg='#999999')
  #canvas.grid(row=0, column=0, sticky=N+S+E+W)
  #vscrollbar.config(command=canvas.yview)
  #hscrollbar.config(command=canvas.xview)
  # make the canvas expandable
  #master.grid_rowconfigure(0, weight=1)
  #master.grid_columnconfigure(0, weight=1)
  frame = Frame(canvas)
  #frame.rowconfigure(1, weight=1)
  #frame.columnconfigure(1, weight=1)
  #canvas.create_window(0, 0, anchor=NW, window=frame)
  #frame.update_idletasks()
  #canvas.config(scrollregion=canvas.bbox("all"))
  """
  vscrollbar = Scrollbar(master)
  vscrollbar.pack(side=RIGHT, fill=Y)
  canvas = Canvas(master, yscrollcommand=vscrollbar.set, bg='#999999')
  frame = Frame(canvas, borderwidth=2, relief=RIDGE, bg="#BFB8FE")
  vscrollbar.config(command=canvas.yview)
  frame.pack(side=LEFT, fill=BOTH)
  #frame.update_idletasks()
  #canvas.config(scrollregion=canvas.bbox("all"))
  #frame = Frame(master)
  return canvas

class Test(Frame):
  def printit(self):
    print "hi"

  def createWidgets(self):
    self.question = Label(self, text="Can Find The BLUE Square??????")
    self.question.pack()

    #self.QUIT = Button(self, text='QUIT', background='red',
    #height=3, command=self.quit)
    #self.QUIT.pack(side=BOTTOM, fill=BOTH)
    #spacer = Frame(self, height="0.25i")
    #spacer.pack(side=BOTTOM)

    # notice that the scroll region (20" x 20") is larger than
    # displayed size of the widget (5" x 5")
    self.draw = Canvas(self, width="5i", height="5i",
    background="white",
    scrollregion=(0, 0, "20i", "20i"))

    self.draw.scrollX = Scrollbar(self, orient=HORIZONTAL)
    self.draw.scrollY = Scrollbar(self, orient=VERTICAL)

    # now tie the three together. This is standard boilerplate text
    self.draw['xscrollcommand'] = self.draw.scrollX.set
    self.draw['yscrollcommand'] = self.draw.scrollY.set
    self.draw.scrollX['command'] = self.draw.xview
    self.draw.scrollY['command'] = self.draw.yview

    # draw something. Note that the first square
    # is visible, but you need to scroll to see the second one.
    self.draw.create_rectangle(0, 0, "3.5i", "3.5i", fill="black")
    self.draw.create_rectangle("10i", "10i", "13.5i", "13.5i", fill="blue")
    # pack 'em up
    self.draw.scrollX.pack(side=BOTTOM, fill=X)
    self.draw.scrollY.pack(side=RIGHT, fill=Y)
    self.draw.pack(side=LEFT)
    return self.draw

  def scrollCanvasX(self, *args):
    print "scrolling", args
    print self.draw.scrollX.get()

  def __init__(self, master=None):
    Frame.__init__(self, master)
    Pack.config(self)
    self.createWidgets()

def AppFrame(master):
  question = Label(master, text="Can Find The BLUE Square??????")
  question.pack()

  #self.QUIT = Button(self, text='QUIT', background='red',
  #height=3, command=self.quit)
  #self.QUIT.pack(side=BOTTOM, fill=BOTH)
  #spacer = Frame(self, height="0.25i")
  #spacer.pack(side=BOTTOM)

  # notice that the scroll region (20" x 20") is larger than
  # displayed size of the widget (5" x 5")
  draw = Canvas(master, width="5i", height="5i",
  background="white",
  scrollregion=(0, 0, "20i", "20i"))
  frame = Frame(draw)

  draw.scrollX = Scrollbar(master, orient=HORIZONTAL)
  draw.scrollY = Scrollbar(master, orient=VERTICAL)

  # now tie the three together. This is standard boilerplate text
  draw['xscrollcommand'] = draw.scrollX.set
  draw['yscrollcommand'] = draw.scrollY.set
  draw.scrollX['command'] = draw.xview
  draw.scrollY['command'] = draw.yview

  # draw something. Note that the first square
  # is visible, but you need to scroll to see the second one.
  draw.create_rectangle(0, 0, "3.5i", "3.5i", fill="black")
  draw.create_rectangle("10i", "10i", "13.5i", "13.5i", fill="blue")
  # pack 'em up
  draw.scrollX.pack(side=BOTTOM, fill=X)
  draw.scrollY.pack(side=RIGHT, fill=Y)
  draw.pack(side=LEFT)
  return draw

#EOF