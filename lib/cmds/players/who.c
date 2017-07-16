
//Change a lot by davantalus@haven
//20040726

// mahkefel oct 2013: made just not show quotes to our precious newbie eyes.

#include <lib.h>
#include <daemons.h>
#include <message_class.h>
//#include "/realms/davantalus/cmds/rank_color.h"

#define IDLE_TIME 60*2

//General color sets defined in rank_color.h
#define TITLE_C "%^BLUE%^"
#define RES "%^RESET%^"

//Immortal color sets
#define DUUK_C   "%^RESET%^GREEN%^"
#define ADMIN_C  "%^RESET%^BOLD%^GREEN%^"
#define SECURE_C "%^RESET%^BOLD%^CYAN%^"
#define ASSIST_C "%^RESET%^CYAN%^"
#define SAGE_C   "%^RESET%^BOLD%^BLUE%^"
#define SPIRIT_C "%^RESET%^BLUE%^"
#define IMM_C    "%^RESET%^MAGENTA%^"
#define ANGEL_C  "%^RESET%^BOLD%^ORANGE%^"

//Mortal color sets
#define EPIC_C   "%^RESET%^BOLD%^BLACK%^"
#define DG_C     "%^RESET%^BOLD%^%^MAGENTA%^"
#define AVATAR_C "%^RESET%^BOLD%^RED%^"
#define LEGEND_C "%^RESET%^RED%^"
#define HM_C     "%^RESET%^YELLOW%^"
#define MORT_C   "%^RESET%^WHITE%^"
#define NEWBIE_C "%^RESET%^BOLD%^WHITE%^"

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
  object *epic   = ({ });
  object *dg     = ({ });
  object *avatar = ({ });
  object *leg    = ({ });
  object *hm     = ({ });
  object *newbie = ({ });

  people = filter(people, (: !$1->GetProperty("assumed") :));
  people = filter(people, (: rank(this_player()) >= $1->GetInvis() :));
  people = filter(people, (: $1->GetName() :) );
  people = filter(people, (: !$1->GetWhoInvis() :) );
  people = filter(people, (: !$1->GetTestChar() :) );

  total = sizeof(people);

  people -= (duuk   = filter(people, (: duukp :)));
  people -= (admin  = filter(people, (: adminp :)));
  people -= (sec    = filter(people, (: securep :)));
  people -= (ast    = filter(people, (: assistp :)));
  people -= (sag    = filter(people, (: sagep :)));
  people -= (spr    = filter(people, (: musep :)) );
  people -= (cre    = filter(people, (: immortalp :)));
  people -= (ang    = filter(people, (: angelp :)));
  people -= (epic   = filter(people, (: epicp :) ));
  people -= (dg     = filter(people, (: demigodp :)));
  people -= (avatar = filter(people, (: avatarp :)));
  people -= (leg    = filter(people, (: legendp :)));
  people -= (hm     = filter(people, (: high_mortalp :)));
  people -= (newbie = filter(people, (: newbiep :)));

/*
  if(who->GetLevel() < 2 && !creatorp(who) ) {
    who->eventPrint("Due to the possibly offensive nature of quotes in the "
    "who listing, the use of this command is restricted to players level 2 "
    "and above.");
    return 1;
  }*/

  who->eventPrint("", MSG_SYSTEM); //spacer

  //Print the title
  if(total == 0)
    who->eventPrint(TITLE_C+ center(sprintf("Haven:  There nobody home!"), wide) +RES, MSG_SYSTEM);
  else
    who->eventPrint( center( "%^RED%^BOLD%^@>%^GREEN%^------   "
                     TITLE_C + "Haven" + "%^GREEN%^   ------%^RED%^BOLD%^<@%^RESET%^", wide), MSG_SYSTEM);

  who->eventPrint("", MSG_SYSTEM); //spacer

  //Usage:  if (total = sizeof(group)) doPrintRank(COLOR, group, groupName, groupNamePlural);

  if (sizeof(duuk))   doPrintRank(who, DUUK_C,    duuk,   "{Supreme Deity} ", "Admins       ");
  if (sizeof(admin))  doPrintRank(who, ADMIN_C,   admin,  "<Greater Deity> ", "Admins       ");
  if (sizeof(sec))    doPrintRank(who, SECURE_C,  sec,    "<Metatron>      ", "Secures      ");
  if (sizeof(ast))    doPrintRank(who, ASSIST_C,  ast,    "<Arch-Angel>    ", "Arches       ");
  if (sizeof(sag))    doPrintRank(who, SAGE_C,    sag,    "<Muse>          ", "Sages        ");
  if (sizeof(spr))    doPrintRank(who, SPIRIT_C,  spr,    "<Spirit>        ", "Spirits      ");
  if (sizeof(cre))    doPrintRank(who, IMM_C,     cre,    "<Immortal>      ", "Immortals    ");
  if (sizeof(ang))    doPrintRank(who, ANGEL_C,   ang,    "<Angel>         ", "Angels       ");

  who->eventPrint("              %^RED%^BOLD%^@>%^GREEN%^}----`--------%^RESET%^", MSG_SYSTEM);
    //Rose spacer
  if (sizeof(epic))   doPrintRank(who, EPIC_C,    epic,   "(Epic Paragon)  ", "Epic Paragons");
  if (sizeof(dg))     doPrintRank(who, DG_C,      dg,     "(Demi-God)      ", "Demi-Gods    ");
  if (sizeof(avatar)) doPrintRank(who, AVATAR_C,  avatar, "|Avatar|        ", "Avatars      ");
  if (sizeof(leg))    doPrintRank(who, LEGEND_C,  leg,    "{Legend}        ", "Legends      ");
  if (sizeof(hm))     doPrintRank(who, HM_C,      hm,     "(High Mortal)   ", "High Mortals ");
  if (sizeof(people)) doPrintRank(who, MORT_C,    people, "[Mortal]        ", "Mortals      ");
  if (sizeof(newbie)) doPrintRank(who, NEWBIE_C,  newbie, " Newbie         ", "Newbies      ");
  who->eventPrint("%^RESET%^", MSG_SYSTEM); //spacer
  

  if(who->GetLevel() < 2 && !creatorp(who) ) {
    // do nothin.
    /*who->eventPrint("Due to the possibly offensive nature of quotes in the "
    "who listing, the use of this command is restricted to players level 2 "
    "and above.");
    return 1;*/
  } else {
    QUOTES_D->eventDisplayQuote(who); //inelegant, quote doesn't have a function to get raw quote
  }
  who->eventPrint("", MSG_SYSTEM); //spacer
  //Center this quote in the future?
  
  return 1;
}

int doPrintRank(object dude, string COLOR, object *group, string groupName, string groupNamePlural)
{
  int wide = dude->GetScreen()[0];

  //Print out the people
  foreach(object twit in sort_array(group, (: SortObByName :)))
  {
    string tmp;
    string zedName;
    tmp = groupName;

    //
    if (twit->GetUndead()) {
      zedName = capitalize( twit->GetKeyName() );
      if(twit->GetSurname()) zedName += " " + twit->GetSurname();
      //if (twit->GetRank() != "Citizen") tmp += strip_colours(twit->GetRank());
      tmp += replace_string( twit->GetShort(), "a zombie", zedName );
    } else {
      tmp += strip_colours(twit->GetShort());
    }

    if (in_input(twit) || in_edit(twit))
      tmp += " [edit]";
    if(sizeof(tmp) > ((wide*2)-20))
    {
      dude->eventPrint( COLOR + groupName + twit->GetName() + ", whose title is too long for you!" + RES, MSG_SYSTEM);
    }
    else if(sizeof(tmp) > wide)
    {
      string lastpart = tmp[wide..-1];
      dude->eventPrint( COLOR + tmp[0..(wide-1)] + RES, MSG_SYSTEM);
    }
    else
      dude->eventPrint( COLOR + tmp + RES, MSG_SYSTEM );
  }
}

int SortObByName(object a, object b)
{
  return strcmp(a->GetShort(), b->GetShort());
}

string GetHelp() {
  return ( "Lists users currently on the mud, highest to lowest rank, with a fun "
           "quote at the bottom." );
}


