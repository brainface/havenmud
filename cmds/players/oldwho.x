#include <lib.h>

#define IDLE_TIME 60*2

inherit LIB_DAEMON;

string *MakeLines(object *list);
int SortObByName(object a, object b);

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

  object *admin  = ({ });
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

/*
debug("duuk", identify(people));
*/
   people = filter(people, (: !$1->GetProperty("assumed") :));
   people = filter(people, (: rank(this_player()) >= $1->GetInvis() :));
  people = filter(people, (: $1->GetName() :) );
  people = filter(people, (: !$1->GetWhoInvis() :) );
  people = filter(people, (: !$1->GetTestChar() :) );

  total = sizeof(people);

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

  paging += ({ center(sprintf("Current users online:  %d", total),
    wide) });
  paging += ({ "%^RESET%^" });

  // Not at all elegant, but easy to read and understand
  if (total = sizeof(newbie))
  {
    paging += ({ sprintf("Newbie:  %d", total) + "%^CYAN%^" });
    paging += MakeLines(newbie);
  }
  if (total = sizeof(people))
  {
    paging += ({ sprintf("Mortal:  %d", total) + "%^ORANGE%^" });
    paging += MakeLines(people);
  }
  if (total = sizeof(hm))
  {
    paging += ({ sprintf("High Mortal:  %d", total) + "%^YELLOW%^" });
    paging += MakeLines(hm);
  }
  if (total = sizeof(leg))
  {
    paging += ({ sprintf("Legend:  %d", total) + "%^BOLD%^GREEN%^" });
    paging += MakeLines(leg);
  }
  if (total = sizeof(avatar))
  {
    paging += ({ sprintf("Avatar:  %d", total) + "%^GREEN%^" });
    paging += MakeLines(avatar);
  }
  if (total = sizeof(dg))
  {
    paging += ({ sprintf("Demigod:  %d", total) + "%^MAGENTA%^" });
    paging += MakeLines(dg);
  }
  if (total = sizeof(ang)) {
  	paging += ({ sprintf("Angel:  %d", total) + "%^RESET%^WHITE%^" });
  	paging += MakeLines(ang);
  	}
  if (total = sizeof(cre))
  {
    paging += ({ sprintf("Immortal:  %d", total) + "%^BLUE%^" });
    paging += MakeLines(cre);
  }
  if (total = sizeof(spr)) {
  	paging += ({ sprintf("Spirit:  %d", total) + "%^BOLD%^MAGENTA%^" });
  	paging += MakeLines(spr);
  	}
  if (total = sizeof(sag))
  {
    paging += ({ sprintf("Sage:  %d", total) + "%^BOLD%^CYAN%^" });
    paging += MakeLines(sag);
  }
  if (total = sizeof(ast))
  {
    paging += ({ sprintf("Assistant Arch:  %d", total) + "%^BOLD%^RED%^" });
    paging += MakeLines(ast);
  } 
  if (total = sizeof(sec))
  {
    paging += ({ sprintf("Secure Arch:  %d", total) + "%^BOLD%^MAGENTA%^" });
    paging += MakeLines(sec);
  }
  if (total = sizeof(admin))
  {
    paging += ({ sprintf("Admin:  %d", total) + "%^BOLD%^BLUE%^" });
    paging += MakeLines(admin);
  }

  who->eventPage(paging);
  return 1;
}

string *MakeLines(object *list)
{
  string *output = ({ });
  foreach (object twit in sort_array(list, (: SortObByName :)))
  {
    string tmp;
    if (in_input(twit) || in_edit(twit)) tmp   = " (edit) ";
    else tmp = "        ";
    tmp += strip_colours(twit->GetShort());
    output += ({ tmp });
  }
  return output + ({ "%^RESET%^" });
}

int SortObByName(object a, object b)
{
  return strcmp(a->GetShort(), b->GetShort());
}
