/*    /cmds/players/biography.c
 *    from the NIghtmare V Object Library
 *    biography
 *    created by Descartes of Borg 951217
 *    made targettable by Amelia@Haven
 *    made legible by Davantalus@Haven 20040730
 *    Kills commented out by Tassadar@Haven 01OCT04
 */

#include <lib.h>
#include <clock.h>
#include <daemons.h>
#include <marriage.h>
#include <message_class.h>

inherit LIB_DAEMON;

#define IMM_START_AGE 0
#define IMMSHAVEAGE 1

mixed cmd(string args)
{
  class marriage *m;
  mapping *deaths;
  mapping kills;
  string *npcs, *tmp, *col1, *col2, *col3;
  string yrstr;
  int x, cols, birth, i, age, startage;
  object who;

  //Targetting checks
  if(creatorp(this_player()) && args)
  {
    if(!(who = find_living(args)))
      return "Target " + args + " could not be found.";
  }
  else
    who = this_player();

  cols = ((int *)this_player()->GetScreen())[0];
  tmp = ({ center("\n%^BLUE%^Biography for " + (string)who->GetShort(),
            cols), "%^RESET%^" });


//**************** AGE ****************//

  if(IMMSHAVEAGE==0){}
  else
  {
    birth = (int)who->GetBirth();
    if(who->GetRace()=="Immortal")
    {
      age = ( query_year(time()) - query_year(birth) + IMM_START_AGE);
      startage = (query_year(birth) - IMM_START_AGE);
      if(startage<1)
        yrstr = (-startage) + " B.N";

      tmp += ({ sprintf("You came into being on the %d%s day of %s, year %s. "
              "(%d years old)", query_date(birth), ordinal(query_date(birth)),
              query_month(birth), yrstr, age) });
    }
    else
    {
      age = ( query_year(time()) - query_year(birth) + 
              SETUP_D->GetStartingAge(who->GetRace()) );
      startage = query_year(birth)-SETUP_D->GetStartingAge(who->GetRace());
      if(startage<1)
        yrstr = (-startage) + " B.N";

      tmp += ({ sprintf("You were born on the %d%s day of %s, year %s. "
              "(%d years old)", query_date(birth), ordinal(query_date(birth)),
              query_month(birth), yrstr, age) });
    }
  }

//**************** MARRIED ****************//

  m = (class marriage *)who->GetMarriages();

  if( !sizeof(m) )
    tmp += ({ "You have never been married." });
  else
  {
    class marriage marr;
    string town;
    marr = m[0];
    if( !marr->DivorceDate )
    {
      x = query_year(marr->WeddingDate);
      if( x < 0 )
        yrstr = (-x) + " B.N.";
      else
        yrstr = x + "";

      town = (string)(marr->Location)->GetTown();
      if( !town || town == "wilderness" )
        town = ".";
      else
        town = " in " + town + ".";
      tmp += ({ "You married " + marr->Spouse + " the " +
                 query_date(marr->WeddingDate) + "" + 
                 ordinal(query_date(marr->WeddingDate)) + " of " +
                 query_month(marr->WeddingDate) + " " + yrstr + town });
      if( sizeof(m) > 1 )
        m = m[1..];
      else
        m = ({});
    }

    if( i = sizeof(m) )
    {
      tmp += ({ "Past marriages:" });
      while(i--)
      {
        string yrstr2;
        marr = m[i];
        x = query_year(marr->WeddingDate);

        if( x < 0 )
          yrstr = (-x) + " BN";
        else
          yrstr = x + "";

        x = query_year(marr->DivorceDate);

        if( x < 0 )
          yrstr2 = (-x) + " BN";
        else
          yrstr2 = x + "";

        town = (string)(marr->Location)->GetTown();

        if( !town || town == "wilderness" )
          town = "";
        else
          town = " in " + town;              
        tmp += ({ "You married " + marr->Spouse + " " +
                  query_month(marr->WeddingDate) + " " +
                  query_date(marr->WeddingDate) + ", " + yrstr +
                  town + ", divorced " +
                  query_month(marr->DivorceDate) + " " +
                  query_date(marr->DivorceDate) + ", " + yrstr2 + "."
               });
      }
    }
  }

// Stops here if you're an imm
  if(who->GetRace()=="Immortal")
  {
    this_player()->eventPage(tmp, MSG_SYSTEM);
    return 1;
  }

//**************** DEATHS ****************//

  deaths = (mapping *)who->GetDeaths();
  if( !(x = sizeof(deaths)) )
    tmp += ({ "%^BLUE%^You have never suffered the pain of death.%^RESET%^" });
  else
  {
    mapping *d1, *d2;
    tmp += ({ "", "%^RED%^Death has cast its shadow over you on the following " +
                    consolidate(x, "occasion") + ":%^RESET%^" });
    foreach(mapping Deaded in deaths)
    {
      tmp += ({ Deaded["enemy"] + " : " + mtime(Deaded["date"]) });
    }
  }
}
//**************** KILLS ****************//
/*
 *  kills = (mapping)STATISTICS_D->GetKills((string)who->GetKeyName());
 * npcs = sort_array(keys(kills), 1);
 *  if( !(x = sizeof(npcs)) )
 *    tmp += ({ "You have never brought harm to another." });
 *  else
 *  {
 *    tmp += ({ "","You are responsible for the deaths of the following:" });
 *    if( x < 3 )
 *    {
 *      col1 = npcs[0..0];
 *      if( x == 2 ) col2 = npcs[1..1];
 *      else col2 = ({});
 *      col3 = ({});
 *    }
 *    else
 *    {
 *      x = x/3;
 *      col1 = npcs[0..(x-1)];
 *      col2 = npcs[x..(x+x-1)];
 *      col3 = npcs[(2*x)..];
 *    }
 *    for(i=0; i<x; i++)
 *   tmp += 
 *     ({ sprintf(
 *            "%:-" + 
 *            (cols/3) + "s%:-" + (cols/3) + "s%s", 
 *            (i >= sizeof(col1)) ? "" :                  
 *            "(" + kills[col1[i]] + ") " + col1[i],
 *            (i >= sizeof(col2)) ? "" :                  
 *            "(" + kills[col2[i]] + ") " + col2[i],
 *            (i >= sizeof(col3)) ? "" :
 *            "(" + kills[col3[i]] + ")"  + col3[i] ) });
 *  }
 *  this_player()->eventPage(tmp, MSG_SYSTEM);
 *  return 1;
 *}
 */

//**************** HELP ****************//
string GetHelp(string str)
{
  string ret = "Syntax: bio\n";
  if(creatorp(this_player()))
  {
    ret+= "        bio <living>\n";
  }
  return (ret +=("\n"
          "Bio gives you a biography of the life you have lived on " 
          "Haven.  This information details such things "
          "as your birth, deaths, and marriages.\n\n"
          "See also: score"));
}
