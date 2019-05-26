struct ListItem {
  int id;
  char *value;
};

/*static ListItem country[] = {
  {9999, "Other"},
  {93, "Afghanistan"},
  {355, "Albania"},
  {213, "Algeria"},
  {684, "American Samoa"},
  {376, "Andorra"},
  {244, "Angola"},
  {101, "Anguilla"},
  {102, "Antigua and Barbuda"},
  {5902, "Antilles"},
  {54, "Argentina"},
  {374, "Armenia"},
  {297, "Aruba"},
  {247, "Ascension Island"},
  {61, "Australia"},
  {43, "Austria"},
  {994, "Azerbaijan"},
  {103, "Bahamas"},
  {973, "Bahrain"},
  {880, "Bangladesh"},
  {104, "Barbados"},
  {120, "Barbuda"},
  {375, "Belarus"},
  {32, "Belgium"},
  {501, "Belize"},
  {229, "Benin"},
  {105, "Bermuda"},
  {975, "Bhutan"},
  {591, "Bolivia"},
  {387, "Bosnia and Herzegovina"},
  {267, "Botswana"},
  {55, "Brazil"},
  {106, "British Virgin Islands"},
  {673, "Brunei"},
  {359, "Bulgaria"},
  {226, "Burkina Faso"},
  {257, "Burundi"},
  {855, "Cambodia"},
  {237, "Cameroon"},
  {107, "Canada"},
  {178, "Canary Islands"},
  {238, "Cape Verde Islands"},
  {108, "Cayman Islands"},
  {236, "Central African Republic"},
  {235, "Chad"},
  {56, "Chile, Republic of"},
  {86, "China"},
  {672, "Christmas Island"},
  {6101,"Cocos-Keeling Islands"},
  {6102, "Cocos (Keeling) Islands"},
  {57, "Colombia"},
  {2691, "Comoros"},
  {243, "Congo, Democratic Republic of (Zaire)"},
  {242, "Congo, Republic of the"},
  {682, "Cook Islands"},
  {506, "Costa Rica"},
  {225, "Cote d'Ivoire (Ivory Coast)"},
  {385, "Croatia"},
  {53, "Cuba"},
  {357, "Cyprus"},
  {42, "Czech Republic"},
  {45, "Denmark"},
  {246, "Diego Garcia"},
  {253, "Djibouti"},
  {109, "Dominica"},
  {110, "Dominican Republic"},
  {593, "Ecuador"},
  {20, "Egypt"},
  {503, "El Salvador"},
  {240, "Equatorial Guinea"},
  {291, "Eritrea"},
  {372, "Estonia"},
  {251, "Ethiopia"},
  {298, "Faeroe Islands"},
  {500, "Falkland Islands"},
  {679, "Fiji"},
  {358, "Finland"},
  {33, "France"},
  {5901, "French Antilles"},
  {594, "French Guiana"},
  {689, "French Polynesia"},
  {241, "Gabon"},
  {220, "Gambia"},
  {995, "Georgia"},
  {49, "Germany"},
  {233, "Ghana"},
  {350, "Gibraltar"},
  {30, "Greece"},
  {299, "Greenland"},
  {111, "Grenada"},
  {590, "Guadeloupe"},
  {671, "Guam, US Territory of"},
  {502, "Guatemala"},
  {224, "Guinea"},
  {245, "Guinea-Bissau"},
  {592, "Guyana"},
  {509, "Haiti"},
  {504, "Honduras"},
  {852, "Hong Kong"},
  {36, "Hungary"},
  {354, "Iceland"},
  {91, "India"},
  {62, "Indonesia"},
  {98, "Iran (Islamic Republic of)"},
  {964, "Iraq"},
  {353, "Ireland"},
  {972, "Israel"},
  {39, "Italy"},
  {112, "Jamaica"},
  {81, "Japan"},
  {962, "Jordan"},
  {705, "Kazakhstan"},
  {254, "Kenya"},
  {686, "Kiribati"},
  {850, "Korea, North"},
  {82, "Korea, South"},
  {965, "Kuwait"},
  {706, "Kyrgyzstan"},
  {856, "Laos"},
  {371, "Latvia"},
  {961, "Lebanon"},
  {266, "Lesotho"},
  {231, "Liberia"},
  {218, "Libyan Arab Jamahiriya"},
  {4101, "Liechtenstein"},
  {370, "Lithuania"},
  {352, "Luxembourg"},
  {853, "Macau"},
  {389, "Macedonia (F.Y.R.O.M.)"},
  {261, "Madagascar"},
  {265, "Malawi"},
  {60, "Malaysia"},
  {960, "Maldives"},
  {223, "Mali"},
  {356, "Malta"},
  {692, "Marshall Islands"},
  {596, "Martinique"},
  {222, "Mauritania"},
  {230, "Mauritius"},
  {269, "Mayotte Island"},
  {52, "Mexico"},
  {691, "Micronesia, Federated States of"},
  {373, "Moldova, Republic of"},
  {377, "Monaco"},
  {976, "Mongolia"},
  {113, "Montserrat"},
  {212, "Morocco"},
  {258, "Mozambique"},
  {95, "Myanmar"},
  {264, "Namibia"},
  {674, "Nauru"},
  {977, "Nepal"},
  {31, "Netherlands"},
  {599, "Netherlands Antilles"},
  {114, "Nevis"},
  {687, "New Caledonia"},
  {64, "New Zealand"},
  {505, "Nicaragua"},
  {227, "Niger"},
  {234, "Nigeria"},
  {683, "Niue"},
  {6722, "Norfolk Island"},
  {47, "Norway"},
  {968, "Oman"},
  {92, "Pakistan"},
  {680, "Palau"},
  {507, "Panama"},
  {675, "Papua New Guinea"},
  {595, "Paraguay"},
  {51, "Peru"},
  {63, "Philippines"},
  {48, "Poland"},
  {351, "Portugal"},
  {121, "Puerto Rico"},
  {974, "Qatar"},
  {262, "Reunion Island"},
  {40, "Romania"},
  {6701, "Rota Island"},
  {7,  "Russia"},
  {250, "Rwanda"},
  {290, "Saint Helena"},
  {115, "Saint Kitts"},
  {1141,"Saint Kitts and Nevis"},
  {122, "Saint Lucia"},
  {508, "Saint Pierre and Miquelon"},
  {116, "Saint Vincent and the Grenadines"},
  {670, "Saipan Island"},
  {378, "San Marino"},
  {239, "Sao Tome and Principe"},
  {966, "Saudi Arabia"},
  {442, "Scotland"},
  {221, "Senegal"},
  {248, "Seychelles"},
  {232, "Sierra Leone"},
  {65, "Singapore"},
  {4201, "Slovakia"},
  {386, "Slovenia"},
  {677, "Solomon Islands"},
  {252, "Somalia"},
  {27, "South Africa"},
  {34, "Spain"},
  {94, "Sri Lanka"},
  {249, "Sudan"},
  {597, "Suriname"},
  {268, "Swaziland"},
  {46, "Sweden"},
  {41, "Switzerland"},
  {963, "Syrian Arab Republic"},
  {886, "Taiwan"},
  {708, "Tajikistan"},
  {255, "Tanzania"},
  {66, "Thailand"},
  {6702,"Tinian Island"},
  {228, "Togo"},
  {690, "Tokelau"},
  {676, "Tonga"},
  {117, "Trinidad and Tobago"},
  {216, "Tunisia"},
  {90, "Turkey"},
  {709, "Turkmenistan"},
  {118, "Turks and Caicos Islands"},
  {688, "Tuvalu"},
  {256, "Uganda"},
  {380, "Ukraine"},
  {971, "United Arab Emirates"},
  {44, "United Kingdom"},
  {598, "Uruguay"},
  {1, "USA"},
  {711, "Uzbekistan"},
  {678, "Vanuatu"},
  {379, "Vatican City"},
  {58, "Venezuela"},
  {84, "Vietnam"},
  {123, "Virgin Islands (USA)"},
  {441, "Wales"},
  {681, "Wallis and Futuna Islands"},
  {685, "Western Samoa"},
  {967, "Yemen"},
  {381, "Yugoslavia"},
  {3811, "Yugoslavia - Serbia"},
  {382, "Yugoslavia - Montenegro"},
  {260, "Zambia"},
  {263, "Zimbabwe"}
};

static countrySize = sizeof(country) / sizeof(country[0]);*/

static ListItem gender[] = {
  {0, "unspecified"},
  {'M', "male"},
  {'F', "female"}
};

static genderSize = sizeof(gender) / sizeof(gender[0]);

static ListItem status[] = {
  {ID_STATUS_OFFLINE, "offline"},
  {ID_STATUS_ONLINE, "online"},
  {ID_STATUS_AWAY, "away"},
  {ID_STATUS_DND, "DND"},
  {ID_STATUS_NA, "N/A"},
  {ID_STATUS_OCCUPIED, "occupied"},
  {ID_STATUS_FREECHAT, "free for chat"},
  {ID_STATUS_INVISIBLE, "invisible"}
};

static statusSize = sizeof(status) / sizeof(status[0]);

static ListItem myEmail[] = {
  {0, "UserInfo"},
  {0, "Mye-mail"}
};

static ListItem myPhone[] = {
  {0, "UserInfo"},
  {0, "MyPhone"}
};

static ListItem birthday[] = {
  {0, "BirthDay"},
  {0, "BirthMonth"},
  {0, "BirthYear"}
};

static ListItem past[] = {
  {0, NULL},
  {0, "Past"},
  {0, "Past"},
  {0, "Text"}
};

static ListItem interest[] = {
  {0, NULL},
  {0, "Interest"},
  {0, "Cat"},
  {0, "Interest"},
  {0, "Text"}
};

#define ILSTRING 1 //������
#define ILLISTWORD 2 //������, ��� id �������� � ���� ��� word
#define ILBIRTHDAY 3 //���� ��������
#define ILBYTE 4 //byte
#define ILWORD 5 //word
#define ILDWORD 6 //dword
#define ILIP 7 //IP
#define ILDATETIME 8 //���� � �����, ���������� � dword
#define ILLISTED1 9
#define ILLISTED2 10
#define ILNOTES 11 //�������. ��� ���� ����������
#define ILTIMEZONE 12 //��������� ���� + ����������� Localtime
#define ILLISTED3 13
#define ILLISTBYTE 14 //������, ��� id �������� � ���� ��� byte
#define ILCOUNTRY 15 //������

struct InfoListItem {
  char *DBName;
  int DBType;
  ListItem *list;
  int listSize;
};

static InfoListItem ICQInfo[] = {
  {"Nick", ILSTRING},
  {"FirstName", ILSTRING},
  {"LastName", ILSTRING},
  {"Gender", ILLISTBYTE, gender, genderSize},
  {"e-mail", ILSTRING},
  {"Birthday", ILBIRTHDAY, birthday},
  {"Age", ILBYTE},
  {"UIN", ILDWORD},
  {"IP", ILIP},
  {"RealIP", ILIP},
  {"MirVer", ILSTRING},
  {"Version", ILWORD},
  {"UserPort", ILWORD},
  {"LogonTS", ILDATETIME},
  {"TickTS", ILDATETIME},
  {"IdleTS", ILDATETIME},
  {"Status", ILLISTWORD, status, statusSize},
  {"Mye-mail", ILLISTED1, myEmail},
  {"Phone", ILSTRING},
  {"Fax", ILSTRING},
  {"Cellular", ILSTRING},
  {"MyPhone", ILLISTED1, myPhone},
  {"Country", ILCOUNTRY},
  {"State", ILSTRING},
  {"ZIP", ILSTRING},
  {"City", ILSTRING},
  {"Street", ILSTRING},
  {"Language1", ILSTRING},
  {"Language2", ILSTRING},
  {"Language3", ILSTRING},
  {"Timezone", ILTIMEZONE},
  {"Company", ILSTRING},
  {"Department", ILSTRING},
  {"Position", ILSTRING},
  {"CompanyCountry", ILCOUNTRY},
  {"CompanyState", ILSTRING},
  {"CompanyZIP", ILSTRING},
  {"CompanyCity", ILSTRING},
  {"CompanyStreet", ILSTRING},
  {"CompanyHomepage", ILSTRING},
  {"Homepage", ILSTRING},
  {"Past", ILLISTED2, past},
  {"Interest", ILLISTED3, interest},
  {"About", ILSTRING},
  {"MyNotes", ILNOTES}
};

static int ICQInfoSize = sizeof(ICQInfo) / sizeof(ICQInfo[0]);

static InfoListItem MSNInfo[] = {
  {"e-mail", ILSTRING},
  {"Status", ILLISTWORD, status, statusSize},
  {"Nick", ILSTRING},
  {"MyNotes", ILNOTES}
};

static int MSNInfoSize = sizeof(MSNInfo) / sizeof(MSNInfo[0]);

struct ProtocolItem {
  char *name;
  InfoListItem *list;
  int listSize;
};

static char *ICQInternalTemplate = "\
<tmplIf name=\"Nick\">Nickname: <tmplVar name=\"Nick\"></tmplIf><tmplIf name=\"FirstName\"><tmplIf name=\"LastName\">\x0D\x0A" \
"First and last name: <tmplVar name=\"FirstName\"> <tmplVar name=\"LastName\"><tmplElse>\x0D\x0A" \
"First name: <tmplVar name=\"FirstName\"></tmplIf><tmplElse><tmplIf name=\"LastName\">\x0D\x0A" \
"Last name: <tmplVar name=\"LastName\"></tmplIf></tmplIf><tmplIf name=\"Gender\">\x0D\x0A" \
"Gender: <tmplVar name=\"Gender\"></tmplIf><tmplIf name=\"e-mail\">\x0D\x0A" \
"Primary e-mail: <tmplVar name=\"e-mail\"></tmplIf><tmplIf name=\"Birthday\">\x0D\x0A" \
"Date of birth: <tmplVar name=\"Birthday\"><tmplIf name=\"Age\">, age: <tmplVar name=\"Age\"></tmplIf><tmplElse><tmplIf name=\"Age\">\x0D\x0A" \
"Age: <tmplVar name=\"Age\"></tmplIf></tmplIf><tmplIf name=\"UIN\">\x0D\x0A" \
"UIN: <tmplVar name=\"UIN\"></tmplIf><tmplIf name=\"IP\">\x0D\x0A" \
"IP external: <tmplVar name=\"IP\"><tmplIf name=\"RealIP\">, internal: <tmplVar name=\"RealIP\"></tmplIf><tmplElse><tmplIf name=\"RealIP\">\x0D\x0A" \
"IP internal: <tmplVar name=\"RealIP\"></tmplIf></tmplIf><tmplIf name=\"MirVer\">\x0D\x0A" \
"ICQ client: <tmplVar name=\"MirVer\"><tmplIf name=\"Version\">, version: <tmplVar name=\"Version\"></tmplIf><tmplIf name=\"UserPort\">, port: <tmplVar name=\"UserPort\"></tmplIf><tmplElse><tmplIf name=\"Version\">\x0D\x0A" \
"ICQ version: <tmplVar name=\"Version\"><tmplIf name=\"UserPort\">, port: <tmplVar name=\"UserPort\"></tmplIf><tmplElse><tmplIf name=\"UserPort\">\x0D\x0A" \
"ICQ port: <tmplVar name=\"UserPort\"></tmplIf></tmplIf></tmplIf><tmplIf name=\"LogonTS\">\x0D\x0A" \
"Online since: <tmplVar name=\"LogonTS\"><tmplIf name=\"TickTS\">, system up: <tmplVar name=\"TickTS\"></tmplIf><tmplIf name=\"IdleTS\">, idle: <tmplVar name=\"IdleTS\"></tmplIf><tmplElse><tmplIf name=\"TickTS\">\x0D\x0A" \
"System up since: <tmplVar name=\"TickTS\"><tmplIf name=\"IdleTS\">, idle: <tmplVar name=\"IdleTS\"></tmplIf><tmplElse><tmplIf name=\"IdleTS\">\x0D\x0A" \
"Idle since: <tmplVar name=\"IdleTS\"></tmplIf></tmplIf></tmplIf><tmplIf name=\"Status\">\x0D\x0A" \
"ICQ status: <tmplVar name=\"Status\"></tmplIf><tmplIf name=\"Mye-mail\">\x0D\x0A" \
"Other e-mails: <tmplVar name=\"Mye-mail\"></tmplIf><tmplIf name=\"Phone\">\x0D\x0A" \
"Phone number: <tmplVar name=\"Phone\"><tmplIf name=\"Fax\">, fax: <tmplVar name=\"Fax\"></tmplIf><tmplIf name=\"Cellular\">, mobile: <tmplVar name=\"Cellular\"></tmplIf><tmplElse><tmplIf name=\"Fax\">\x0D\x0A" \
"Fax number: <tmplVar name=\"Fax\"><tmplIf name=\"Cellular\">, mobile: <tmplVar name=\"Cellular\"></tmplIf><tmplElse><tmplIf name=\"Cellular\">\x0D\x0A" \
"Mobile phone number: <tmplVar name=\"Cellular\"></tmplIf></tmplIf></tmplIf><tmplIf name=\"MyPhone\">\x0D\x0A" \
"Other phone numbers: <tmplVar name=\"MyPhone\"></tmplIf><tmplIf name=\"Country\">\x0D\x0A" \
"Address: <tmplVar name=\"Country\"><tmplIf name=\"State\"> <tmplVar name=\"State\"></tmplIf><tmplIf name=\"ZIP\"> <tmplVar name=\"ZIP\"></tmplIf><tmplIf name=\"City\"> <tmplVar name=\"City\"></tmplIf><tmplIf name=\"Street\"> <tmplVar name=\"Street\"></tmplIf><tmplElse><tmplIf name=\"State\">\x0D\x0A" \
"Address: <tmplVar name=\"State\"><tmplIf name=\"ZIP\"> <tmplVar name=\"ZIP\"></tmplIf><tmplIf name=\"City\"> <tmplVar name=\"City\"></tmplIf><tmplIf name=\"Street\"> <tmplVar name=\"Street\"></tmplIf><tmplElse><tmplIf name=\"ZIP\">\x0D\x0A" \
"Address: <tmplVar name=\"ZIP\"><tmplIf name=\"City\"> <tmplVar name=\"City\"></tmplIf><tmplIf name=\"Street\"> <tmplVar name=\"Street\"></tmplIf><tmplElse><tmplIf name=\"City\">\x0D\x0A" \
"Address: <tmplVar name=\"City\"><tmplIf name=\"Street\"> <tmplVar name=\"Street\"></tmplIf><tmplElse><tmplIf name=\"Street\">\x0D\x0A" \
"Address: <tmplVar name=\"Street\"></tmplIf></tmplIf></tmplIf></tmplIf></tmplIf><tmplIf name=\"Language1\">\x0D\x0A" \
"Spoken languages: <tmplVar name=\"Language1\"><tmplIf name=\"Language2\">, <tmplVar name=\"Language2\"></tmplIf><tmplIf name=\"Language3\">, <tmplVar name=\"Language3\"></tmplIf><tmplElse><tmplIf name=\"Language2\">\x0D\x0A" \
"Spoken languages: <tmplVar name=\"Language2\"><tmplIf name=\"Language3\">, <tmplVar name=\"Language3\"></tmplIf><tmplElse><tmplIf name=\"Language3\">\x0D\x0A" \
"Spoken language: <tmplVar name=\"Language3\"></tmplIf></tmplIf></tmplIf><tmplIf name=\"Timezone\">\x0D\x0A" \
"Timezone: <tmplVar name=\"Timezone\">, local time: <tmplVar name=\"Localtime\"></tmplIf><tmplIf name=\"Company\">\x0D\x0A" \
"Company: <tmplVar name=\"Company\"></tmplIf><tmplIf name=\"Department\">\x0D\x0A" \
"Department: <tmplVar name=\"Department\"></tmplIf><tmplIf name=\"Position\">\x0D\x0A" \
"Position: <tmplVar name=\"Position\"></tmplIf><tmplIf name=\"CompanyCountry\">\x0D\x0A" \
"Company address: <tmplVar name=\"CompanyCountry\"><tmplIf name=\"CompanyState\"> <tmplVar name=\"CompanyState\"></tmplIf><tmplIf name=\"CompanyZIP\"> <tmplVar name=\"CompanyZIP\"></tmplIf><tmplIf name=\"CompanyCity\"> <tmplVar name=\"CompanyCity\"></tmplIf><tmplIf name=\"CompanyStreet\"> <tmplVar name=\"CompanyStreet\"></tmplIf><tmplElse><tmplIf name=\"CompanyState\">\x0D\x0A" \
"Company address: <tmplVar name=\"CompanyState\"><tmplIf name=\"CompanyZIP\"> <tmplVar name=\"CompanyZIP\"></tmplIf><tmplIf name=\"CompanyCity\"> <tmplVar name=\"CompanyCity\"></tmplIf><tmplIf name=\"CompanyStreet\"> <tmplVar name=\"CompanyStreet\"></tmplIf><tmplElse><tmplIf name=\"CompanyZIP\">\x0D\x0A" \
"Company address: <tmplVar name=\"CompanyZIP\"><tmplIf name=\"CompanyCity\"> <tmplVar name=\"CompanyCity\"></tmplIf><tmplIf name=\"CompanyStreet\"> <tmplVar name=\"CompanyStreet\"></tmplIf><tmplElse><tmplIf name=\"CompanyCity\">\x0D\x0A" \
"Company address: <tmplVar name=\"CompanyCity\"><tmplIf name=\"CompanyStreet\"> <tmplVar name=\"CompanyStreet\"></tmplIf><tmplElse><tmplIf name=\"CompanyStreet\">\x0D\x0A" \
"Company address: <tmplVar name=\"CompanyStreet\"></tmplIf></tmplIf></tmplIf></tmplIf></tmplIf><tmplIf name=\"CompanyHomepage\">\x0D\x0A" \
"Company website: <tmplVar name=\"CompanyHomepage\"></tmplIf><tmplIf name=\"Homepage\">\x0D\x0A" \
"Homepage: <tmplVar name=\"Homepage\"></tmplIf><tmplIf name=\"Past\">\x0D\x0A" \
"Past background: <tmplVar name=\"Past\"></tmplIf><tmplIf name=\"Interest\">\x0D\x0A" \
"Interests: <tmplVar name=\"Interest\"></tmplIf><tmplIf name=\"About\">\x0D\x0A" \
"About: <tmplVar name=\"About\"></tmplIf><tmplIf name=\"MyNotes\">\x0D\x0A" \
"Notes: <tmplVar name=\"MyNotes\"></tmplIf>\
";

static char *MSNInternalTemplate = "\
<tmplIf name=\"Nick\">Nickname: <tmplVar name=\"Nick\"></tmplIf><tmplIf name=\"e-mail\">\x0D\x0A" \
"Primary e-mail: <tmplVar name=\"e-mail\"></tmplIf><tmplIf name=\"Status\">\x0D\x0A" \
"MSN status: <tmplVar name=\"Status\"></tmplIf><tmplIf name=\"MyNotes\">\x0D\x0A" \
"Notes: <tmplVar name=\"MyNotes\"></tmplIf>\
";

static char *neutralTemplate = "\
Nickname: <tmplVar name=\"Nick\">\x0D\x0A\
\x0D\x0A\
(This is neutral for all protocols internal template.\x0D\x0A\
You can select another template at Miranda Options -> Plugins ->\x0D\x0A\
look-in)\
";

static ProtocolItem protocol[] = {
  {"ICQ", ICQInfo, ICQInfoSize},
  {"MSN", MSNInfo, MSNInfoSize}
};

static int protocolSize = sizeof(protocol) / sizeof(protocol[0]);

struct InternalTemplateItem {
  char *name;
  char *templ;
};

static InternalTemplateItem intTempl[] = {
  {"ICQ internal template", ICQInternalTemplate},
  {"MSN internal template", MSNInternalTemplate},
  {"Neutral template", neutralTemplate}
};

static int intTemplSz = sizeof(intTempl) / sizeof(intTempl[0]);
