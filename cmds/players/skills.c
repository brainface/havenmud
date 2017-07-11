/*    /cmds/player/skills.c
 *    from the Dead Souls LPC Library
 *    command to view skills
 *    created by Descartes of Borg 950409
 *     made targettable by Amelia@Haven
 *    - Moved map function to GetLine for readability, added a max skill
 *      level display for each skill, grouped in classes. (Blitz 960122/0404)
 */
 
#include <lib.h>
#include <daemons.h>
 
inherit LIB_DAEMON;
 
string GetLine(string skill, object who)
{
  int x, max;
  mapping mp = (mapping)who->GetSkill(skill);

  if (!sizeof(mp)) return 0;
  max = (int)who->GetLevel() + 1;
  max *= 2;
  if (max < mp["level"]) max = mp["level"];
  return sprintf("%:-20s: %:-7s ", skill, (mp["level"] + "/" + max));
}

int FigureMyScore(object who) {
  string *sk = who->GetSkills();
  int score = 0, sk_bonus = 0;
  foreach(string skill in (sk)) {
    sk_bonus = SKILLS_D->GetSkillCost(skill);
    if (who->GetSkillClass(skill) == 1)  sk_bonus = sk_bonus * 3;
    if (who->GetSkillClass(skill) == 2)  sk_bonus = sk_bonus * 2;  
    score += who->GetSkillLevel(skill) * sk_bonus;
  }
  return score;
}

int cmd(string args)
{
  string *skills, *primes, *secs;
  string ret;
  int x, scr;
  object printto = this_player();
  object who = printto;

  if ((creatorp(this_player()) && !args) || angelp(this_player()))
  {
    message("system", "Creators have no skills, get a life.", this_player());
    return 1;
  }

  if (args && creatorp(this_player()))
  {
    if (!who = find_living(args))
    {
      printto->eventPrint("Unable to find " + args + ".");
      return 1;
    }
    if (creatorp(who))
    {
      printto->eventPrint("Come now.  You know that's wrong.");
      return 1;
    }
}
  if (!args) args = who->GetKeyName();
    printto->eventPrint(
             "%^CYAN%^%^BOLD%^Skills for " + 
             capitalize(args) +
             ", a level " + who->GetLevel() + " " +
             (string)who->GetMoralityDescription() + " (" + who->GetMorality() + ") " +
             who->GetGender() + " " +  
             who->GetRace() +
            (who->GetClass() ? " " + who->GetClass() : "") +
           " (" + who->GetReligion() + ")" +
            ":%^RESET%^"
            );
  ret = "";
  scr = ((int *)printto->GetScreen())[0];
 
  skills = sort_array((string *)who->GetSkills(), 1);

  if (!sizeof(skills))
  {
    ret += "You are without skills.\n";
    printto->eventPrint(ret);
     printto->eventPrint("Experience Points: " + who->GetExperience());
    return 1;
  }
  secs = primes = ({ });

  foreach (string skill in skills)
  {
    switch (who->GetSkillClass(skill))
    {
      case 1:
        primes += ({skill});
        break;
      case 2:
        secs += ({skill});
        break;
    }
  }

  skills = skills - secs - primes;

//    skills = skills - (primes = filter(skills,
//                      (: who->GetSkillClass($1) == 1 :)));
//    skills = skills - (secs = filter(skills,
//                      (: who->GetSkillClass($1) == 2 :)));

  skills = map(skills, (: GetLine :), who);
  primes = map(primes, (: GetLine :), who);
  secs   = map(secs, (: GetLine :), who);
  foreach (mixed sarray in ({ primes, secs, skills }) )
  {
    int y, i = sizeof(sarray);
    while(i--) if( (y = strlen(sarray[i])) > x ) x = y;
  }

  x = scr/(x+2);
  ret = "\n";
  ret += "%^BOLD%^%^CYAN%^Primary skills:%^RESET%^\n";
  ret += format_page(primes, x);
  ret += "\n%^BOLD%^%^CYAN%^Secondary skills:%^RESET%^\n";
  ret += format_page(secs, x);
  ret += "\n%^BOLD%^%^CYAN%^Other skills:%^RESET%^\n";
  ret += format_page(skills, x);
  printto->eventPage(explode(ret, "\n"));

  //Quick and dirty hack for points needed to advance
  primes = who->GetPrimarySkills();
  x = who->GetLevel() * 2 * sizeof(primes);
  foreach (string sk in primes) x -= who->GetBaseSkillLevel(sk);
  printto->eventPrint("Experience Points: " + who->GetExperience());
  if (x<=0 && who->GetLevel() == 19 && !who->GetApprovedStory()) 
    printto->eventPrint("You must first create a character story to advance.");
  if (who->GetLevel() < 500) {
    if (x <= 0 ) {
      printto->eventPrint("You are prepared to advance.  Seek out a trainer and <ask trainer to advance>.");
      } else {
    printto->eventPrint(sprintf("You need %d more primary skill points to advance.", x));
      }
    } else {
    	printto->eventPrint("You have achieved the highest level for a player.");
    }
  printto->eventPrint("You last levelled " + ctime(who->GetLastLevel()) + ".");
  printto->eventPrint("Current skill point score: " + FigureMyScore(who) + ".");
  return 1;
}

 
string GetHelp(string foo)
{
  return "Syntax: <skills>\n\n"
         "Lists all of your skills as well as how skilled you are "
         "at the skill in question.\n\n"
         "See also: stats, status";
}
