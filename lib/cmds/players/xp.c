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
  printto->eventPrint("Experience Points: " + who->GetExperience());
  return 1;
}
string GetHelp(string foo)
{
  return "Syntax: <xp>\n\n"
         "Displays current XP total.\n\n"
         "See also: stats, status";
}
