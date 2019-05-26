look-in 0.5.0.0 Miranda IM plugin



Contents
--------

Dedication/About/Installation/History/TODO/Bugs/Templates/Contact



Dedication
----------

for aiki



About
-----

Adds an extra tab to the user details dialog to display all user
details at only one page



Installation
------------

Copy look-in.dll and folder "template" into Miranda IM plugin directory or
use Miranda Installer



History
-------

0.5.0.0

* templates changed

* internal ICQ & MSN templates added into dll file (increase dll file size)

* the newline characters isn't cutted now from template

* template tag <tmplBr> not used now

* fixed bug with multiply opened user info dialogs and update info button

* fixed display of pull-down menus in the options

* internal neutral template (default for all protocols) added

0.4.0.0

* free form view of user details based on flexible template parser

* basic & default templates

* plugin/protocol/template corresponding selection in settings dialog

* some details not accessible now by reason of unfinded bug... :(

0.3.0.0

* some more compact details view

* date/time format fixed

* small memory leak fixed

* available strings for translation

* MSN, AIM, Gadu-Gadu, Jabber, Yahoo and other protocols support
(some unexpected feature. Details are viewed as ICQ details)

* multi protocol dll's support

* some bugs with translation fixed

* ok/cancel/apply buttons at options dialog fixed

* update button fixed

0.2.0.0

* some more compact details view

* added all not listed user details

* possible to hide other user info tabs from dialog
(experimental!!! very buggy [may be... :) ]!!! only for default
Miranda language!!! use at your own risk!!! p.s. because Miranda
don't support this feature)

* options

* installer support

0.1.0.0

* first release



TODO
----

* preview of template in options

* ability to change template in user info dialog

* tabstopped edit control

* correct MSN, AIM, Gadu-Gadu, Jabber, Yahoo and other protocols
support (you need them?)

* rewrite all this with assembler to smaller file size (laziness...)

* my English :)


Bugs
----

look-in author <look-in@mail.ru>



Templates
---------

Tempate is the plain text file with user info representation.
In this file may be included some types of tags. Parser process this
tags and replace them with some values. Tags is case sensitive.

Variable tag

<tmplVar name="...">

This tag is replaced with value of variable, which name is shown
in this tag. If value isn't exist, tag replaced with blank string.
Available variables for ICQ protocol is:

Nick
FirstName
LastName
Gender
e-mail
Birthday
Age
UIN
IP - external IP
RealIP - internal IP
MirVer - ICQ client
Version - ICQ client version
UserPort - ICQ client port
LogonTS - online since
TickTS - system up since
IdleTS - idle since
Status - ICQ status
Mye-mail - additional e-mail's
Phone
Fax
Cellular
MyPhone - additional phone numbers
Country
State
ZIP
City
Street
Language1
Language2
Language3
Timezone
Localtime - available only if timezone exist
Company
Department
Position
CompanyCountry
CompanyState
CompanyZIP
CompanyCity
CompanyStreet
CompanyHomepage
Homepage - user homepage
Past - past background
Interest
About
MyNotes

Variables for MSN protocol:

Nick
e-mail
Status
MyNotes


Condition tag

<tmplIf name="...">...</tmplIf>
<tmplIf name="...">...<tmplElse>...</tmplIf>

Condition tag is used to show or hide some text. The main body of
this tag is shown when variable, which name is used, is exist. When
variable isn't exist, shown the alternative body of this tag.

In the tag body can be used all other tags: variable, condition.
The enclosing of the tags is unlimited.



Contact
-------

look-in author <look-in@mail.ru>
