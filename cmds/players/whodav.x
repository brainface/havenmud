//Change a lot by davantalus@haven
//20040726

#include <lib.h>
#include <daemons.h>
//#include "/realms/davantalus/cmds/rank_color.h"

#define IDLE_TIME 60*2

//General color sets defined in rank_color.h
#define TITLE_C "%^BLUE%^"
#define RES "%^RESET%^"

//Immortal color sets
#define DUUK_C "%^GREEN%^"
#define ADMIN_C "%^BOLD%^GREEN%^"
#define SECURE_C "%^BOLD%^CYAN%^"
#define ASSIST_C "%^CYAN%^"
#define SAGE_C "%^BOLD%^BLUE%^"
#define SPIRIT_C "%^BLUE%^"
#define IMM_C "%^MAGENTA%^"
#define ANGEL_C "%^BOLD%^WHITE%^"

//Mortal color sets
#define DG_C "%^BOLD%^%^MAGENTA%^"
#define AVATAR_C "%^BOLD%^RED%^"
#define LEGEND_C "%^RED%^"
#define HM_C "%^YELLOW%^"
#define MORT_C "%^ORANGE%^"
#define NEWBIE_C "%^WHITE%^"


inherit LIB_DAEMON;

object *duuk   = ({ });
object *admin  = ({ });


int SortObByName(object a, object b);
int doPrintRank(object dude, string COLOR, object *group, string groupName, string groupNamePlural);

static void create() {
  ::create();
  SetNoClean(1);
}

int cmd()
{
  object who = this_player();
  object *people = users();
  int wide = who->GetScreen()[0];
  int total;
  string *paging = ({ });
  string *tmp    = ({ });


  object *sec    = ({ });
  object *ast    = ({ });
  object *sag    = ({ });
  object *spr    = ({ });
  object *cre    = ({ });
  object *ang    = ({ });
  object *dg     = ({ });
  object *avatar = ({ });
  object *leg    = ({ });
  object *hm     = ({ });
  object *newbie = ({ });

  people = filter(people, (: !$1->GetProperty("assumed") :));
  people = filter(people, (: rank(this_player()) > $1->GetInvis() :));
  people = filter(people, (: $1->GetName() :) );
  people = filter(people, (: !$1->GetWhoInvis() :) );
  people = filter(people, (: !$1->GetTestChar() :) );

  total = sizeof(people);

  people -= (duuk   = filter(people, (: duukp :)));
  people -= (admin  = filter(people, (: adminp :)));
  people -= (sec    = filter(people, (: securep :)));
  people -= (ast    = filter(people, (: assistp :)));
  people -= (sag    = filter(people, (: sagep :)));
  people -= (spr    = filter(people, (: spiritp :)) );
  people -= (cre    = filter(people, (: immortalp :)));
  people -= (ang    = filter(people, (: angelp :)));
  people -= (dg     = filter(people, (: demigodp :)));
  people -= (avatar = filter(people, (: avatarp :)));
  people -= (leg    = filter(people, (: legendp :)));
  people -= (hm     = filter(people, (: high_mortalp :)));
  people -= (newbie = filter(people, (: newbiep :)));

  who->eventPrint("");
  //Print the title
  if(total == 0)
    who->eventPrint(TITLE_C+ center(sprintf("Haven:  There nobody home!"), wide) +RES);
  else
    who->eventPrint(TITLE_C+ center(sprintf( "-+- Haven -+-"), wide) +RES);


  //Usage:  if (total = sizeof(group)) doPrintRank(COLOR, group, groupName, groupNamePlural);

  if (sizeof(duuk))   doPrintRank(who, ADMIN_C,   duuk,   "Admin", "Admin");
  if (sizeof(admin))  doPrintRank(who, ADMIN_C,   admin,  "therest", "Admin");
  if (sizeof(sec))    doPrintRank(who, SECURE_C,  sec,    "Secure", "Secures");
  if (sizeof(ast))    doPrintRank(who, ASSIST_C,  ast,    "Arch", "Arches");
  if (sizeof(sag))    doPrintRank(who, SAGE_C,    sag,    "Sage", "Sages");
  if (sizeof(spr))    doPrintRank(who, SPIRIT_C,  spr,    "Spirit", "Spirits");
  if (sizeof(cre))    doPrintRank(who, IMM_C,     cre,    "Immortal", "Immortals");
  if (sizeof(ang))    doPrintRank(who, ANGEL_C,   ang,    "Angel", "Angels");

  if (sizeof(dg))     doPrintRank(who, DG_C,      dg,     "Demi-God", "Demi-Gods");
  if (sizeof(avatar)) doPrintRank(who, AVATAR_C,  avatar, "Avatar", "Avatars");
  if (sizeof(leg))    doPrintRank(who, LEGEND_C,  leg,    "Legend", "Legends");
  if (sizeof(hm))     doPrintRank(who, HM_C,      hm,     "High Mortal", "High Mortals");
  if (sizeof(people)) doPrintRank(who, MORT_C,    people, "Mortal", "Mortals");
  if (sizeof(newbie)) doPrintRank(who, NEWBIE_C,  newbie, "Newbie", "Newbies");
  who->eventPrint("");
  QUOTES_D->eventDisplayQuote(who); //inelegant, quote doesn't have a function to get raw quote
  who->eventPrint("");
  //Center this quote in the future?
  return 1;
}

int doPrintRank(object dude, string COLOR, object *group, string groupName, string groupNamePlural)
{
  //Duuk making my life miserable
  if((sizeof(duuk)!=0 && sizeof(admin)>0) && groupName=="therest")
    {}
  else
  {
    //Print out the rest of the ranks
    string out = "";
    if( sizeof(group)>1 )
    //Two more lines of duuk code
      out = groupNamePlural;
    else if(groupNamePlural=="Admins" && sizeof(duuk)+sizeof(admin)>1)
      out = groupNamePlural;
    else out = RES + groupName;
    dude->eventPrint(out);
  }
  //Print out the people
  foreach(object twit in sort_array(group, (: SortObByName :)))
  {
    string tmp;
    if (in_input(twit) || in_edit(twit)) tmp   = " (edit) ";
    else tmp = "        ";
    tmp += strip_colours(twit->GetShort());
    dude->eventPrint( COLOR + tmp + RES );
  }
}

int SortObByName(object a, object b)
{
  return strcmp(a->GetShort(), b->GetShort());
}

string GetHelp() {
  return ( "Lists users currently on the mud, highest to lowest rank, with a fun "
           "quote at the bottom. See also: who" );
}
