import VS
import Director
import fg_util
import vsrandom
import faction_ships
import universe
import dynamic_universe
import dynamic_news
global dnewsman_
dnewsman_ = dynamic_news.NewsManager()

plr=0
basefac='neutral'
def formatShip(ship):
    where=ship.find(".blank")
    if (where!=-1):
        ship=ship[0:where]
    return ship.capitalize()

def formatCargoCategory(ship):
    where=ship.rfind("/")
    if (where!=-1):
        ship=ship[where+1:]
    return ship.capitalize()

#Credit to Peter Trethewey, master of python and all things nefarious
def getSystemsKAwayNoFaction( start, k ):
    set = [start]#set of systems that have been visited
    pathset = [[start]]#parallel data structure to set, but with paths
    pathtor = [[start]]#parallel data structure to raw return systems with path
    r = [start] #raw data structure containing systems n away where n<=k
    for n in range(0,k):
        set.extend(r)
        pathset.extend(pathtor)
        r=[]
        pathtor=[]
        for iind in range(len(set)):
            i = set[iind]
            l = universe.getAdjacentSystemList(i)
            for jind in range(len(l)):
                j=l[jind]
                if not (j in set or j in r):
                    r.append(j)
                    pathtor.append(pathset[iind]+[j])
    return pathtor

def getSystemsNAway (start,k,preferredfaction):
    l = getSystemsKAwayNoFaction(start,k)
    if (preferredfaction==None):
        return l
    lbak=l
    if (preferredfaction==''):
        preferredfaction=VS.GetGalaxyFaction(start)
    i=0
    while i <len(l):
        if (VS.GetRelation(preferredfaction,VS.GetGalaxyFaction(l[i][-1]))<0):
            del l[i]
            i-=1
        i+=1
    if (len(l)):
        return l
    return lbak

syscreds=750

def GetRandomCompanyName():
    bnl=[]
    print 'reading company names '
    filename = '../universe/companies.txt'
    try:
        f = open (filename,'r')
        bnl = f.readlines()
        f.close()
    except:
        return ''
    for i in range(len(bnl)):
        bnl[i]=bnl[i].rstrip()
    import vsrandom
    idx = vsrandom.randint(0,len(bnl)-1)
    return bnl[idx]
    
def GetRandomCargoBrief():
    bnl=[]
    brief=''
    print 'generating cargo briefing'
    filename = '../universe/cargo_brief.txt'
    try:
        f = open (filename,'r')
        bnl = f.readlines()
        f.close()
    except:
        return ''
    for i in range(len(bnl)):
        bnl[i]=bnl[i].rstrip()
    import vsrandom
    idx = vsrandom.randint(0,len(bnl)-1)
    brief = bnl[idx]
    return brief
    
def getCargoName(category):
    l=category.split('/')
    if len(l)>1:
        cargo = l[len(l)-1]+' '+l[0]
    else:
        cargo = category
    cargo = cargo.replace('_',' ')
    return cargo


def getMissionDifficulty ():
    import difficulty
    tmp=difficulty.getPlayerUnboundDifficulty(VS.getCurrentPlayer())
    if (tmp>8):
        tmp=8
    return tmp

def getPriceModifier(isUncapped):
    import difficulty
    if (not difficulty.usingDifficulty()):
        return 1.0
    if (isUncapped):
        return getMissionDifficulty()/.5+.9
    return VS.GetDifficulty()/.5+.9

def howMuchHarder(makeharder):
    import difficulty
    if  (makeharder==0):
        return 0
    udiff = getMissionDifficulty()
    if (udiff<=1):
        return 0
    return int(udiff*2)-1

def processSystem(sys):
    k= sys.split('/')
    if (len(k)>1):
        k=k[1]
    else:
        k=k[0]
    return k
totalMissionNumber=0
insysMissionNumber=0
def checkInsysNum():
    global insysMissionNumber
    if insysMissionNumber:
        insysMissionNumber=0
        return True
    return False
def checkMissionNum():
    global totalMissionNumber
    if totalMissionNumber:
        totalMissionNumber=0
        return True
    return False
def checkCreatedMission():
    if (checkMissionNum()+checkInsysNum()>0):
        return True
    return False
def isFixerString(s):
    k=str(s)
    if (len(k)<2):
        return 0
    if (k[1]=='F'):
        return 1
    if (k[1]=='G'):
        return 2
    return 0
def writemissionname(name,path,isfixer):
    if (isfixer==0):
        if path[-1]==VS.getSystemFile():
            name="Interplanetarische_"+name
            global insysMissionNumber
            insysMissionNumber+=1
        else:
            global totalMissionNumber
            totalMissionNumber+=1
    Director.pushSaveString(plr, "mission_names", name)

    
def writedescription(name):
    Director.pushSaveString(plr, "mission_descriptions", name.replace("_"," "))
def writemissionsavegame (name):
    Director.pushSaveString(plr, "mission_scripts", name)
def eraseExtras():
    import sys
    len=Director.getSaveStringLength(plr, "mission_scripts")
    if (len!=Director.getSaveStringLength(plr, "mission_names") or len!=Director.getSaveStringLength(plr, "mission_descriptions")):
        sys.stdout.write("Warning: Number of mission descs., names and scripts are unequal.\n")
    if len>0:
        for i in range(len-1,-1,-1):
            Director.eraseSaveString(plr, "mission_scripts", i)
            Director.eraseSaveString(plr, "mission_names", i)
            Director.eraseSaveString(plr, "mission_descriptions", i)

fixerpct=0.05
guildpct=0.4
def restoreFixerPct():
    global fixerpct
    global guildpct
    fixerpct=.0625
    guildpct=.4
def mungeFixerPct():
    global fixerpct
    global guildpct
    fixerpct=.0375
    guildpct=1

def generateCleansweepMission(path,numplanets,enemy):
    fighterprob=vsrandom.random()*.75+.25;
    capshipprob=0.0
    if (vsrandom.random()<.2):
        capshipprob=vsrandom.random()*.25;
    forceattack=vsrandom.randrange(0,2)
    cleansweep=vsrandom.randrange(0,2)
    minships=maxships=vsrandom.randrange(1,4)
    creds = numplanets*(cleansweep*4+1+capshipprob*4+.25*forceattack)*500*minships*fighterprob
    creds*=getPriceModifier(False)
    addstr=""
    isFixer=vsrandom.random()
    if isFixer<fixerpct:
        creds*=2
        addstr+="#F#bases/fixers/confed.spr#Unterhalte Dich mit dem konfoederiertem Offizier#Danke. Deine Hilfe macht den Weltraum zu einem weniger gefaehrlichem Platz.#\n"
    elif isFixer<guildpct:
        creds*=1.5
        if (cleansweep):
            addstr+="#G#Bounty#\n"
        else:
            addstr+="#G#Patrol#\n"
    missiontype="patrol_enemies"
    additional=""
    additionalinstructions=""
    patrolorclean="Patrouille"
    dist=1500
    if (cleansweep):
        dist=1500
        additional=",1"
        patrolorclean="Saeuberungsaktion"
        missiontype="cleansweep"
        additionalinstructions+="Vernichte alle Streitkraefte, die du aufgespuert hast, um die Bezahlung zu erhalten."
    if (capshipprob):
        additionalinstructions+="Feindliche Kriegsschiffe koennen in der Gegend sein."

    writemissionsavegame (addstr+"import %s\ntemp=%s.%s(0, %d, %d, %d, %s,'',%d,%d,%f,%f,'%s',%d%s)\ntemp=0\n"%(missiontype,missiontype,missiontype,numplanets, dist, creds, str(path),minships,maxships,fighterprob,capshipprob,enemy,forceattack,additional))
    writedescription("Die Obrigkeit haette gerne einen detaillierten Scan des %s System. Wir verlangen, dass %d Navigationspunkte in dem zu scannenden Gebiet kontrolliert werden. Die Bezahlung fuer diese Mission betraegt %d Kredite. Begegnungen_mit_%s Streitkraeften sind moeglich. %s"%(processSystem(path[-1]),numplanets,creds,enemy,additionalinstructions))
    ispoint="e"
    if numplanets==1:
        ispoint=""
    writemissionname("%s/Kontrolliere %d Punkt%s im %s System"%(patrolorclean,numplanets,ispoint, processSystem(path[-1])),path,isFixerString(addstr))   

def generatePatrolMission (path, numplanets):
    dist=1000
    creds = numplanets*500
    creds*=getPriceModifier(False)
    addstr=""
    isFixer=vsrandom.random()
    if isFixer<fixerpct:
        creds*=2
        addstr+="#F#bases/fixers/confed.spr#Unterhalte Dich mit dem konfoederiertem Offizier#Danke. Deine Hilfe macht den Weltraum zu einem weniger gefaehrlichem Platz.#\n"
    elif isFixer<guildpct:
        creds*=1.5
        addstr+="#G#Patrol#\n"
    writemissionsavegame (addstr+"import patrol\ntemp=patrol.patrol(0, %d, %d, %d, %s)\ntemp=0\n"%(numplanets, dist, creds, str(path)))
    writedescription("Die lokale Obrigkeit haette gerne einen detaillierten Scan des %s Systems. Wir verlangen, dass %d Navigationspunkte in dem zu scannenden Gebiet kontrolliert werden. Die Bezahlung fuer diese Mission betraegt %d Kredite."%(processSystem(path[-1]),numplanets,creds))
    ispoint="e"
    if numplanets==1:
        ispoint=""
    writemissionname("Patrouille/Kontrolliere %d Punkt%s im %s System"%(numplanets,ispoint, processSystem(path[-1])),path,isFixerString(addstr))   

def isNotWorthy(fac):
    return VS.GetRelation(fac,VS.getPlayer().getFactionName())<0

def generateEscortLocal(path,fg,fac):
    if (isNotWorthy(fac)):
        return
    typ = fg_util.RandomShipIn(fg,fac)
    if typ in faction_ships.unescortable:
        typ = faction_ships.unescortable[typ]
    enfac = faction_ships.get_enemy_of(fac)
    diff=vsrandom.randrange(1,4)
    waves=vsrandom.randrange(0,5-diff)
    incoming=vsrandom.randrange(0,2)
    enfg =fg_util.AllFGsInSystem(enfac,path[-1])
    creds=3500.0*diff*(1+waves);
    if (len(enfg)):
      enfg=enfg[vsrandom.randrange(0,len(enfg))]
    else:
      enfg=''
    isFixer=vsrandom.random()
    addstr=""
    if isFixer<fixerpct:
        creds*=2
        addstr+="#F#bases/fixers/merchant.spr#Unterhalte Dich mit dem Kaufmann#Danke. Ich vertraue dir, dass du meinen Geschaeftspartner sicher geleiten wirst, bis er sein Ziel erreicht.#\n"
    elif isFixer<guildpct:
        creds*=1.5
        addstr+="#G#Escort#\n"
    additionalinfo="zu dem Sprungpunkt"
    if (incoming):
        additionalinfo="von dem Sprungpunkt zu einer nahen Basis"
    writemissionsavegame(addstr+"import escort_local\ntemp=escort_local.escort_local('%s',0,%d,%d,500,%d,%d,'%s',(),'','%s','','%s','%s')"%(enfac,diff,waves,creds,incoming,fac,enfg,fg,typ))
    # From plueschinger to avoid sometimes squadrons and sometimes not
    # we mention the squadrons or konvois later in the following message
    if "Squadron" == fg[-8:]:
         fg = fg[:-9]
    # end of plueschingers addition
    writedescription("Eine Eskorte %s ist erforderlich fuer die %s Klasse %s der Raumschiffe aus der %s Schwadron in diesem System. Angriffe von der %s Gruppe sind moeglich. Sie werden bezahlt mit %d Krediten, falls das Raumschiff in diesem Sternensystem ueberlebt, bis es seinen Zielort erreicht."%(additionalinfo,formatShip(typ),fac,fg,enfac,int(creds)))
    writemissionname("Eskorte/Eskortiere den_%s in dem_%s Konvoi"%(fac,fg),[path[-1]],isFixerString(addstr))

def generateEscortMission (path,fg,fac):
    ###
    if (isNotWorthy(fac)):
        return
    typ = fg_util.RandomShipIn(fg,fac)
    if typ in faction_ships.unescortable:
        typ = faction_ships.unescortable[typ]
    diff=vsrandom.randrange(0,6)    
    creds=500*diff+1.2*syscreds*len(path)
    creds*=getPriceModifier(False)
    addstr=""
    isFixer=vsrandom.random()
    if isFixer<fixerpct:
        creds*=2
        addstr+="#F#bases/fixers/merchant.spr#Talk to the Merchant#Danke. Ich vertraue dir, dass du meinen Geschaeftspartner sicher geleiten wirst, bis er sein Ziel erreicht.#\n"
    elif isFixer<guildpct:
        creds*=1.5
        addstr+="#G#Escort#\n"
    writemissionsavegame (addstr+"import escort_mission\ntemp=escort_mission.initrandom('%s', %d, %g, 0, 0, %s, '','%s','%s')\ntemp=0\n"%(fac, diff, float(creds), str(path),fg,typ))
    # From plueschinger to avoid sometimes squadrons and sometimes not
    # we mention the squadrons or konvois later in the following message
    if "Squadron" == fg[-8:]:
         fg = fg[:-9]
    # end of plueschingers addition
    writedescription("Die %s %s in dem %s Konvoi benoetigt eine Eskorte nach %s. Die Belohnung fuer eine erfolgreiche Eskorte betraegt %d Kredite."%(fac,formatShip(typ),fg, processSystem(path[-1]),creds))
    writemissionname("Eskorte/Eskortiere den_%s aus der_%s Schwadron in das_%s System"%(fac,fg,processSystem(path[-1])),path,isFixerString(addstr))     

def changecat(category):
    l=category.split('/')
    if len(l)>1:
        return l[-1]+'_'+l[0]
    else:
        return category

def pathWarning(path,isFixer):
    global dnewsman_
    message = str()
    factions = list()
    if isFixer:
        message+="\nAlle Vorkehrungen und Investitionen, die von Dir getroffen worden, um den Erfolg dieser Mission zu sichern, gehen auf Deine Kosten."
    else:
        for system in path:
            sysfac = VS.GetGalaxyFaction(system)
            if sysfac not in factions:
                factions.append(sysfac)
        message+="\n\nDu bist verantwortlich fuer den Erfolg dieser Mission. Alle Vorkehrungen und Investitionen, die von Dir getroffen worden, um den Erfolg dieser Mission zu sichern, gehen auf Deine Kosten. Mit diesem Wissen im Hinterkopf teile ich Dir mit, dass Du durch Systeme reisen wirst, die beherrscht werden von den "
        if len(factions) == 1:
            message+=dnewsman_.data.getFactionData(factions[0],'full')[0]+"."
        else:
            message+="folgenden Gruppierungen: "
            jj=0
            for fac in factions:
                jj+=1               
                message+=dnewsman_.data.getFactionData(fac,'full')[0]
                if jj<len(factions)-1:
                    message+=", "
                elif jj<len(factions):
                    message+=" und den "
    return message
		
def adjustQuantityDifficulty(max):
   return 3+int((max-3)*VS.GetDifficulty())

def isHabitable (system):
    planetlist=VS.GetGalaxyProperty(system,"planets")
    if (len(planetlist)==0):
        return False
    planets=planetlist.split(' ')
    for planet in planets:
        if planet=="i" or planet=="a" or planet=="am" or planet=="u" or planet=="com" or planet=="bd" or planet=="s" or planet=="o" or planet=="at" or planet=="bs" or planet=="bdm" or planet=="bsm" or planet=="f" or planet=="fm" or planet=="t":
            return True
    print str(planets)+ " Not in Habitable List"
    return False

def generateCargoMission (path, numcargos,category, fac):
    if (isNotWorthy(fac)):
        return  
    launchcap=(vsrandom.random()>=.97)
    if (not launchcap) and not isHabitable(path[-1]):
        return
    diff=vsrandom.randrange(0,adjustQuantityDifficulty(6))
    creds=250*numcargos+500*diff+syscreds*len(path)+5000*(category[:10]=="Contraband")+20000*(category[:9]=="starships")
    addstr=""
    creds*=getPriceModifier(False)
    isFixer=vsrandom.random()
    if isFixer<fixerpct:
        creds*=2
        addstr+="#F#bases/fixers/merchant.spr#Unterhalte Dich mit dem Kaufmann#Danke. Ich vertraue dir, dass du die Fracht erfolgreich liefern wirst.#\n"
    elif isFixer<guildpct:
        creds*=1.5
        addstr+="#G#Cargo#\n"
    writemissionsavegame (addstr+"import cargo_mission\ntemp=cargo_mission.cargo_mission('%s', 0, %d, %d, %g, %d, 0, '%s', %s, '')\ntemp=0\n"%(fac, numcargos, diff, creds, launchcap, category, str(path)))
    if (category==''):
        category='generic'
    randCompany = GetRandomCompanyName()
    if (randCompany==''):
        strStart = "Wir muessen "
    else:
    	  strStart = randCompany+" seeks delivery of "    	  
    brief = GetRandomCargoBrief()
    if (brief<>''):
        composedBrief = brief.replace('$CL',randCompany)
        composedBrief = composedBrief.replace('$CG',formatCargoCategory(category))
        composedBrief = composedBrief.replace(' $DB','')
        composedBrief = composedBrief.replace('$DS',processSystem(path[-1]))
        composedBrief = composedBrief.replace('$PY',str(int(creds)))
        writedescription(composedBrief)
    else:
        writedescription(strStart+"Fracht (%s) in das %s System liefern. Die Mission ist uns %d Kredite wert. Du wirst die Fracht zu einer Basis liefern, die bewohnt wird von den %s.%s"%(formatCargoCategory(category), processSystem(path[-1]),creds,fac,pathWarning(path,isFixer<guildpct)))
    # avoid supplies supplies
    if "upplies" == category[-7:]:
        category = category[:-9]
    writemissionname("Fracht/Liefere_%s in das_%s_System"%(changecat(category),processSystem(path[-1])),path,isFixerString(addstr))

def generateRescueMission(path,rescuelist):
    makemissionharder=vsrandom.randrange(0,2)
    numships = vsrandom.randrange(1,adjustQuantityDifficulty(6))+howMuchHarder(makemissionharder)
    creds = (numships+len(path))*vsrandom.randrange(2041,3140)
    creds*=getPriceModifier(makemissionharder!=0)
    if (creds>45000):
        creds=47000
    writemissionsavegame("import rescue\nntemp=rescue.rescue(%d,0,'%s',%d,'%s','%s',%s)\nntemp=0"%(creds,rescuelist[0],numships,rescuelist[2],rescuelist[1],str(path)))
    writedescription("SOS! Ich bin ein %s Pilot in einer Rettungskapsel, der von mindestens %d %s Raumschiffen angegriffen wird. Ich bitte um unverzuegliche Hilfe im %s System und biete dafuer %d Kredite fuer eine sichere Rueckkehr zu einem lokalen Planeten, auf dem ich mich erholen kann."%(rescuelist[0],numships,rescuelist[2],processSystem(path[-1]),creds))
    writemissionname("Rettung/Rette_%s vor den_%s_Schiffen"%(rescuelist[0],rescuelist[2]),path,0)

def generateBountyMission (path,fg,fac):
    typ = fg_util.RandomShipIn(fg,fac)
    cap = faction_ships.isCapital(typ)
    makemissionharder=vsrandom.randrange(0,2)
    diff=vsrandom.randrange(0,adjustQuantityDifficulty(7))+howMuchHarder(makemissionharder)
    runaway=(vsrandom.random()>=.75)
    creds=1000+2000*runaway+500*diff+syscreds*len(path)
    if (cap):
        creds*=4

    finalprice=creds+syscreds*len(path)
    finalprice*=getPriceModifier(False)
    addstr=""
    isFixer=vsrandom.random()
    if isFixer<fixerpct:
        finalprice*=2
        addstr+="#F#bases/fixers/hunter.spr#Unterhalte Dich mit dem Kopfgeldjaeger#Wir bezahlen dich bei erfolgreicher Beendung der Mission. Und noch ein weiser Ratschlag auf deinen Weg -- Wir haben uns niemals getroffen."
        if (runaway):
            addstr += '#Ausserdem-- wir haben Informationen, dass das Angriffsziel ueber Deinen Angriff informiert sein koennte und bereit ist zu verschwinden. Beeil Dich!'
        addstr+="#\n"
    elif isFixer<guildpct:
        creds*=1.5
        addstr+="#G#Bounty#\n"
    writemissionsavegame(addstr+"import bounty\ntemp=bounty.bounty(0, 0, %g, %d, %d, '%s', %s, '', '%s','%s')\ntemp=0\n"%(finalprice, runaway, diff, fac, str(path), fg,typ))
    diffstr = ""
    if (diff==1):
        diffstr="Es wird vermutet, dass das feindliche Schiff einen Geleitschutz von einem Raumschiff hat."
    if (diff>1):
        diffstr="Es wird vermutet, dass das feindliche Schiff einen Geleitschutz von %d Raumschiffen hat."%diff
    writedescription("Ein %s Raumschiff aus der %s hat unsere Operationen im %s System gestoert. Die Belohnung fuer die Vernichtung des genannten Schiffes betraegt %d Kredite. %s"%(formatShip(typ),fg, processSystem(path[-1]), finalprice,diffstr))
    # change faction names like pirates to piraten
    if "es" == fac[-2:]:
        fac = fac[:-1] + "n"
    if (cap):
        writemissionname ("Kopfgeldjagd/Jagd auf ein_%s_Kriegsschiff im_%s_System"%(fac,processSystem(path[-1])),path,isFixerString(addstr))
    else:
        writemissionname ("Kopfgeldjagd/Jagd auf ein_%s_Raumschiff im_%s_System"%(fac,processSystem(path[-1])),path,isFixerString(addstr))

def generateDefendMission (path,defendfg,defendfac, attackfg,attackfac):
    if (isNotWorthy(defendfac)):
        return
    #defendtyp = fg_util.RandomShipIn(defendfg,defendfac)
    attacktyp = fg_util.RandomShipIn(attackfg,attackfac)                    
    isbase=fg_util.BaseFGInSystemName(path[-1])==defendfg
    creds=1000
    minq = 1
    maxq = adjustQuantityDifficulty(5)
    makemissionharder=vsrandom.randrange(0,2)
    quantity = vsrandom.randrange(minq,maxq)+howMuchHarder(makemissionharder)
    reallydefend = "1"
    if (vsrandom.randrange(0,4)==0):
        reallydefend="0"
    addstr=""
    creds=creds*quantity+syscreds*len(path)
    creds*=getPriceModifier(makemissionharder)
    isFixer=vsrandom.random()
    if isFixer<fixerpct:
        creds*=2
        addstr+="#F#bases/fixers/confed.spr#Unterhalte Dich mit dem konfoederiertem Offizier#Danke. Dein Engagement wird den Konfoederierten auf lange Sicht helfen. Wir schaetzen die Unterstuetzung durch die Gemeinschaft der Kopfgeldjaeger sehr.#\n"
    elif isFixer<guildpct:
        creds*=1.5
        addstr+="#G#Defend#\n"
    writemissionsavegame(addstr+"import defend\ntemp=defend.defend('%s', %d, %d, 8000.0, 100000.0, %g, %s, %d, '%s', %s, '%s', '%s', '%s', '%s')\ntemp=0\n"%
                         (attackfac, 0, quantity, creds, reallydefend, isbase, defendfac, str(path), '',attackfg, attacktyp,defendfg))
    iscapitol=""
    if isbase:
        iscapitol="Kriegs-"
    if quantity == 1:
        starship = "Raumschiff"
    else:
        starship = "Raumschiffen"
    # change faction names like pirates to piraten
    if "es" == attackfac[-2:]:
        attackfac = attackfac[:-1] + "n"
    writedescription("Eine %s Angriffsschwadron mit dem Namen %s ist mit der Absicht hierher gesprungen, eines von unseren %sSchiffen in dem %s System anzugreifen.\n Deine Aufgabe ist es, sie zu vernichten bevor sie unser Raumschiff eliminieren.\n Unser Geheimdienst vermutet, dass die Schwadron aus %d %s der %s Klasse besteht. Deine Belohnung betraegt %d Kredite."%(attackfac, attackfg, iscapitol, processSystem(path[-1]),quantity,starship,formatShip(attacktyp),creds))
    writemissionname("Schutz/Beschuetze die_%s vor den_%s"%(defendfac, attackfac),path,isFixerString(addstr))


def generateWingmanMission(fg, faction):
    numships=vsrandom.randrange(1,4)
    creds=10000+15000*numships
    writemissionsavegame("import wingman\newmission = wingman.wingman (%f, '%s', %d, 0)\newmission=0"%(creds, faction, numships))
    s="Ein Pilot"
    EorA="mann"
    are="is"
    if numships > 1:
        s=str(numships)+" Piloten"
        EorA="maenner"
        are="sind"
    writedescription(s+" aus der %s Zivilisation %s bereit, dir zu helfen und mit dir zu kaempfen, wenn du %d Kredite bezahlst."%(faction, are, creds))
    writemissionname("Fluegelmaenner/Miete_%d_%s_Fluegel%s"%(numships,faction,EorA),[VS.getSystemFile()],0)
    
    
def GetFactionToDefend(thisfaction, fac, cursys):
    m = fg_util.FGsInSystem ("merchant",cursys)
    nummerchant=len(m)
    m+=fg_util.FGsInSystem (thisfaction,cursys)
    numthisfac=len(m)
    m+=fg_util.FGsInSystem (fac,cursys)
    return (m,nummerchant,numthisfac)

def contractMissionsFor(fac,minsysaway,maxsysaway):
    global totalMissionNumber
    global insysMissionNumber
    totalMissionNumber=0
    insysMissionNumber=0
    facnum=faction_ships.factionToInt(fac)
    enemies = list(faction_ships.enemies[facnum])
    script=''
    cursystem = VS.getSystemFile()
    thisfaction = VS.GetGalaxyFaction (cursystem)
    preferredfaction=None
    if (VS.GetRelation (fac,thisfaction)>=0):
        preferredfaction=thisfaction#try to stay in this territory
    l=[]
    num_wingmen=2
    num_rescue=2
    num_defend=1
    num_idefend=2
    num_bounty=1
    num_ibounty=1
    num_patrol=1
    num_ipatrol=1
    num_escort=1
    num_iescort=1
    for i in range (minsysaway,maxsysaway+1):
        for j in getSystemsNAway(cursystem,i,preferredfaction):
            import dynamic_battle
            if (i<2 and num_rescue>0):
                if j[-1] in dynamic_battle.rescuelist:
                    generateRescueMission(j,dynamic_battle.rescuelist[j[-1]])
                    if checkCreatedMission():
                        num_rescue-=1
#            if (0 and i==0):
#                generateRescueMission(j,("confed","Shadow","pirates"))
            l = dynamic_battle.BattlesInSystem(j[-1])
            nodefend=1
            for k in l:
                if (VS.GetRelation(fac,k[1][1])>=0):
                    if ((j[-1]==VS.getSystemFile() and num_idefend<=0) or (j[-1]!=VS.getSystemFile() and num_defend<=0)):
                        mungeFixerPct()
                        print "Munged"
                    else:
                        nodefend=0
                    generateDefendMission(j,k[1][0],k[1][1],k[0][0],k[0][1])
                    restoreFixerPct()
                    if checkInsysNum():
                        num_idefend-=1
                    if checkMissionNum():
                        num_defend-=1
                    print "Generated defendX with insys at: "+str(num_idefend)+" and outsys at "+str (num_defend)
            if preferredfaction:
                (m,nummerchant,numthisfac)=GetFactionToDefend(thisfaction, fac, j[-1])
                for kk in faction_ships.enemies[faction_ships.factiondict[thisfaction]]:
                    k=faction_ships.intToFaction(kk)
                    for mm in fg_util.FGsInSystem(k,j[-1]):
                        if (i==0 or vsrandom.randrange(0,4)==0):#fixme betterthan 4
                            if nodefend and len(m) and vsrandom.random()<.4:
                                if 1:#for i in range(vsrandom.randrange(1,3)):
                                    insys=(j[-1]==VS.getSystemFile())
                                    if (insys and num_idefend<=0):
                                        mungeFixerPct()
                                    elif (num_defend<=0 and not insys):
                                        mungeFixerPct()
                                    rnd=vsrandom.randrange(0,len(m))
                                    def_fg=m[rnd]
                                    def_fac = "merchant"
                                    if rnd>=nummerchant:
                                        def_fac= thisfaction
                                    if rnd>=numthisfac:
                                        def_fac = fac
                                    generateDefendMission(j,def_fg,def_fac,mm,k)
                                    restoreFixerPct()
                                    if checkInsysNum():
                                        num_idefend-=1
                                    if checkMissionNum():
                                        num_defend-=1
                                    print "Generated defendY with insys at: "+str(num_idefend)+" and outsys at "+str (num_defend)
                                nodefend=0
                            elif ((i==0 or vsrandom.random()<.5)):
                                if ((j[-1]==VS.getSystemFile() and num_ibounty<=0) or (j[-1]!=VS.getSystemFile() and num_bounty<=0)):
                                   mungeFixerPct()
                                generateBountyMission(j,mm,k)
                                restoreFixerPct()
                                if checkInsysNum():
                                    print " decrementing INSYS bounty to "+str(num_ibounty)
                                    num_ibounty-=1
                                if checkMissionNum():
                                    print " decrementing bounty to "+str(num_bounty)
                                    num_bounty-=1


                numescort = vsrandom.randrange(0,2)
                if (numescort>len(m)):
                    numescort=len(m)
                count=0
                for k in m:
                    if (i==0):
                        if vsrandom.random()<.92:
                            count+=1
                            continue
                    elif vsrandom.random()<.97:
                        count+=1
                        continue
                    f = "merchant"
                    if count>=nummerchant:
                        f= thisfaction
                    if count>=numthisfac:
                        f = fac
                    if (vsrandom.random()<.25):
                        if (num_wingmen>0):
                            generateWingmanMission(k,f)
                            num_wingmen-=1
                    elif (i==0):
                        if (vsrandom.random()<.25):
                            if num_iescort<=0:
                                mungeFixerPct()
                            generateEscortLocal(j,k,f)
                            restoreFixerPct()
                            if checkCreatedMission():                    
                                num_iescort-=1
                    else:
                        if num_escort<=0:
                            mungeFixerPct()
                        generateEscortMission(j,k,f)
                        restoreFixerPct()
                        if checkCreatedMission():                    
                            num_escort-=1

                    count+=1
            mincount=-2
            if i==0:
                mincount=1
            for k in range(vsrandom.randrange(mincount,4)): ###FIXME: choose a better number than 4.
                if k<0:
                    k=0
                rnd=vsrandom.random()
                if (rnd<.15):    # 15% - nothing
                    pass
                if (rnd<.5 or i==0):    # 35% - Patrol Mission
                    if ((j[-1]==VS.getSystemFile() and num_ipatrol<=0) or (j[-1]!=VS.getSystemFile() and num_patrol<=0)):
                        mungeFixerPct()
                    if (vsrandom.randrange(0,2) or j[-1] in faction_ships.fortress_systems):
                        generatePatrolMission(j,vsrandom.randrange(4,10))
                    else:
                        generateCleansweepMission(j,vsrandom.randrange(4,10),faction_ships.get_enemy_of(fac))
                    restoreFixerPct()
                    if checkInsysNum():
                        num_ipatrol-=1
                    if checkMissionNum():
                        num_patrol-=1
                        
                else:   # 50% - Cargo mission
                    numcargos=vsrandom.randrange(1,25)
                    if numcargos>20:
                        numcargos=20
                    category=''
                    if (rnd>.87 and fac!='confed' and fac != "ISO" and fac!="militia" and fac!="homeland-security" and fac!="kilrathi"):
                        category='Contraband'
                    else:
                        for myiter in range (100):
                            carg=VS.getRandCargo(numcargos,category)
                            category=carg.GetCategory()
                            if (category[:10]!='Contraband' and category.find('upgrades')!=0 and (category.find('starships')!=0 or rnd>.999)):
                                break 
                            if (myiter!=99):
                                category=''
#                    print "CATEGORY OK "+category
                    generateCargoMission(j,numcargos,category,fac)

def CreateMissions(minsys=0,maxsys=4):
    eraseExtras()
    i=0
    global plr,basefac
    plrun=VS.getPlayer()
    plr=plrun.isPlayerStarship()
    un=VS.getUnit(i)
    while(un):
        i+=1
        if (un.isDocked(plrun)):
            break
        un=VS.getUnit(i)
    if (un):
        basefac=un.getFactionName()
    if (basefac=='neutral'):
        basefac=VS.GetGalaxyFaction(VS.getSystemFile())
    contractMissionsFor(basefac,minsys,maxsys)
    import news
    news.processNews(plr)
