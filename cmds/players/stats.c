/*    /cmds/player/skills.c
 *    from the Dead Souls LPC Library
 *    command to view skills
 *    created by Descartes of Borg 950409
 *     made targettable by Amelia@Haven
 *    - Moved map function to GetLine for readability, added a max skill
 *      level display for each skill, grouped in classes. (Blitz 960122/0404)
 */
 
#include <lib.h>
 
inherit LIB_DAEMON;
 
string GetLine(string skill, object who) {
  int x, max;
  mapping mp = (mapping)who->GetStat(skill);
  return sprintf("%:-14s: %d/%d", skill, who->GetStatLevel(skill), who->GetBaseStatLevel(skill));
}

int cmd(string args) {
  string *skills, *primes, *secs, *avgs, *belows;
  string ret;
  int x, scr;
  object printto = this_player();
  object who = printto;

  if ((creatorp(this_player()) && !args) || angelp(this_player()))  {
    message("system", "Creators have no skills, get a life.", this_player());
    return 1;
  }

  if (args && creatorp(this_player()))  {
    if (!who = find_living(args))    {
      printto->eventPrint("Unable to find " + args + ".");
      return 1;
    }
    if (creatorp(who))    {
      printto->eventPrint("Come now.  You know that's wrong.");
      return 1;
    }
  }
  if (!args) args = who->GetKeyName();
    printto->eventPrint(
             "%^BLUE%^%^BOLD%^Stats for " +  capitalize(args) + ", a level " + who->GetLevel() + " " +
             who->GetGender() + " " + who->GetRace() +
            (who->GetClass() ? " " + who->GetClass() : "") + ":%^RESET%^"
            );
  ret = "";
  scr = ((int *)printto->GetScreen())[0];
 
  skills = sort_array((string *)who->GetStats(), 1);

  if (!sizeof(skills))
  {
    ret += "You are without stats!\n";
    printto->eventPrint(ret);
    return 1;
  }
  avgs = secs = primes = belows = ({ });

  foreach (string skill in skills)
  {
    switch (who->GetStatClass(skill))
    {
      case 1:
        primes += ({skill});
        break;
      case 2:
        secs += ({skill});
        break;
      case 3:
        avgs += ({ skill });
        break;
      case 4:
        belows += ({ skill });
        break;
    }
  }

  skills = skills - secs - primes - avgs - belows;

//    skills = skills - (primes = filter(skills,
//                      (: who->GetSkillClass($1) == 1 :)));
//    skills = skills - (secs = filter(skills,
//                      (: who->GetSkillClass($1) == 2 :)));

  skills = map(skills, (: GetLine :), who);
  primes = map(primes, (: GetLine :), who);
  secs   = map(secs, (: GetLine :), who);
  avgs   = map(avgs,   (: GetLine :), who);
  belows = map(belows, (: GetLine :), who);
  foreach (mixed sarray in ({ primes, secs, avgs, belows, skills }) )
  {
    int y, i = sizeof(sarray);
    while(i--) if( (y = strlen(sarray[i])) > x ) x = y;
  }

  x = scr/(x+2);
  ret = "\n";
  ret += "%^BOLD%^%^BLUE%^Primary stats:%^RESET%^\n";
  if (sizeof(primes)) { ret += format_page(primes, x); } else { ret += "No primary stats.\n"; }
  ret += "%^BOLD%^%^BLUE%^Secondary stats:%^RESET%^\n";
  if (sizeof(secs)) { ret += format_page(secs, x); } else { ret += "No secondary stats.\n" ; }
  ret += "%^BOLD%^BLUE%^Average stats:%^RESET%^\n";
  if (sizeof(avgs)) { ret += format_page(avgs, x); } else { ret +=  "No average stats.\n" ; }
  ret += "%^BOLD%^%^BLUE%^Below Average stats:%^RESET%^\n";
  if (sizeof(belows)) { ret += format_page(belows, x); } else { ret +=  "No below average stats.\n" ; }
  ret += "%^BOLD%^%^BLUE%^Abysmal stats:%^RESET%^\n";
  if (sizeof(skills)) { ret += format_page(skills, x); } else { ret +=  "No abysmal stats.\n"; }
  printto->eventPage(explode(ret, "\n"));

  //Quick and dirty hack for points needed to advance
  printto->eventPrint("You last levelled " + ctime(who->GetLastLevel()) + ".");
  if (who->GetCustomStats())
    printto->eventPrint("You have " + who->GetCustomStats() + " customization points remaining.  <help customize>");
  return 1;
}

 
string GetHelp(string g) {
    return "Syntax: <stats>\n\n"
	    "Lists all of your stats as well as how skilled you are "
	    "at the skill in question.\n\n"
	    "See also: stats, status";
}
