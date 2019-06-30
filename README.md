PLATOTERM for Apple IIgs 0.5 Alpha
===============================

What is PLATOTERM?
-------------------

PLATOTERM is a terminal emulator for your Apple IIgs to access CYBIS services now 
available on the Internet utilizing a WIFI Modem.

For the purposes of this documentation. PLATO and CYBIS are interchangeable
names for the same platform.

What services are currently available to access via PLATOTERM?
-----------------------------------------------------------------
As of writing this preliminary documentation (September 2018), there are
two major CYBIS systems running. CYBER1.ORG and IRATA.ONLINE.

WHAT IS PLATO? (aka CYBIS?)
----------------------------

(from the PLATO wikipedia page:)

PLATO (Programmed Logic for Automatic Teaching Operations), was the first
generalized computer-asisted instruction system. Starting in 1960, it ran
on the University of Illinois ILLIAC I computer. By the late 1970s, it
supported several thousand graphics terminals distributed worldwide, running
on nearly a dozen different networked mainframe computers. Many modern
concepts in multi-user computing were originally developed on PLATO, including
forums, message boards, online testing, e-mail, chat rooms, picture languages,
instant messaging, remote screen sharing, and multi-player games.

What is CYBER1.ORG?
--------------------

CYBER1.ORG is a CYBIS system initially set up in 2004, as a haven for
ex-PLATO users to experience a classic PLATO author experience.

CYBER1.ORG is home to many thousands of classic PLATO lessons and
notesfiles which have been restored from various sources, and have
been made available in the interests of preserving PLATO.

What is IRATA.ONLINE?
----------------------

IRATA.ONLINE is a CYBIS system that has been set up for the benefit of
the greater vintage computing community, in the interest to provide
a unique experience that can be accessed on a wide variety of
vintage computers with a bitmapped graphics display. To this end,
IRATA.ONLINE develops PLATOTERM for dozens of platforms, so that they
can access CYBIS systems, as well as provide a community and learning
infrastructure for vintage computing users of all types, in the hopes
that as a cohesive community, something unique can hopefully
emerge.

What is the connection between IRATA.ONLINE and CYBER1.ORG?
-------------------------------------------------------------

CYBER1.ORG and IRATA.ONLINE are independent of one another. With that said,
the reason IRATA.ONLINE and PLATOTERM exist, are because of the efforts of
CYBER1.ORG to not only preserve a running PLATO system, and provide the
necessary information for interested parties to write terminal software
to access CYBIS systems, but also in their effort to produce a publically
available distribution of CYBIS that others who are interested may also
run their own CYBIS installation. IRATA.ONLINE is a direct result of the
public release of this distribution.

What do I need to run PLATOTERM and connect to CYBIS?
------------------------------------------------------

* An Apple IIgs or compatible machine

This version of PLATOTERM is intended for Apple IIgs systems with at
least 512K of RAM.

* An ethernet card and Marinetti correctly configured.

This build currently uses Marinetti for connectivity, and thus can
work with any card that directly supports Marinetti. This has
been tested with the Uthernet and Uthernet II cards, as well
as the Uthernet emulation in GSPlus, which is currently used for
PLATOTERM development.

For IRATA.ONLINE, You do not require an account, as the guest 
account can be used. Feel free to sign-up for an account at 
http://www.irata.online/

Video mode support
-----------------

The current build of PLATOTERM uses the 320 pixel mode, to get
16 colors per screen. PLATOTERM uses QuickDraw II and takes
over the screen completely, re-mapping the palette as new
colors are requested. Any colors more than the initial 16 are
ignored.

Starting PLATOTERM
-------------------

PLATOTERM can be started by selecting the PLATOTERM Icon on the
disk.

Exiting PLATOTERM
------------------

Pressing APPLE-X will exit the program, and return control to
ProDOS 16.

PLATOTERM Setup
----------------

This current build has no setup, all communication parameters
are determined by Marinetti.

Using PLATOTERM
----------------

Upon start, PLATOTERM will attempt to initialize the connection
to Marinetti, if not already active, and ask for a hostname
to connect to. By default, if a hostname is not provided,
IRATA.ONLINE:8005 will be used.

If a host name does not contain a : and a port #, then it will
default to connecting to port 8005, which is the standard
ASCII port for PLATO communication.

PLATO Keyboard
---------------

PLATO terminals had a lot of very special keys, which must be mapped to
equivalent keys on a PC keyboard. The following table shows the
PLATO and equivent PC keys:

| PLATO	| IIgs
|--            |--                   
|ANS	|CONTROL-A                 
|BACK	|CONTROL-B                 
|BACK1	|CONTROL-SHIFT-B           
|COPY	|CONTROL-C                 
|COPY1	|CONTROL-SHIFT-C           
|DATA	|CONTROL-D                 
|DATA1	|CONTROL-SHIFT-D           
|EDIT	|CONTROL-E                 
|EDIT1	|CONTROL-SHIFT-E           
|FONT	|CONTROL-F                 
|DIVIDE	|CONTROL-G                 
|HELP	|APPLE-H                
|HELP1	|APPLE-SHIFT-H          
|LAB	        |CONTROL-L                 
|LAB1	|CONTROL-SHIFT-L           
|MICRO	|CONTROL-M                 
|NEXT	|ENTER                  
|NEXT1	|SHIFT-ENTER            
|SUPER	|CONTROL-P                 
|SUPER1	|CONTROL-SHIFT-P           
|SQUARE	|CONTROL-Q                 
|ACCESS	|CONTROL-SHIFT-Q           
|ERASE	|CONTROL-R                 
|ERASE1	|CONTROL-SHIFT-R           
|STOP	|CONTROL-S                 
|STOP1	|CONTROL-SHIFT-S           
|TERM	|CONTROL-T                 
|MULTIPLY|CONTROL-X                 
|SUB	        |CONTROL-Y                 
|SUB1	|CONTROL-SHIFT-Y           
|SIGMA	|CONTROL-+                 
|DELTA	|CONTROL--                 
|ASSIGN	|ESC                    

Further information
--------------------

Should you need further information, updates, etc. You can check:

* IRATA.ONLINE website: http://www.irata.online/
* IRATA.ONLINE facebook: http://www.facebook.com/irataonline/

Don't forget to check out http://www.cyber1.org/

The author can be reached on IRATA.ONLINE as thomas cherryhomes / atari
