/* Languages command.  Accepts a string arg if creator.
 *
 * Displays all languages along with either a vague value
 * for players or an actual numeric value for immortals.
 * Duuk@Haven
 */
#include <lib.h>
void ShowLanguageMessage(string, object);
inherit LIB_DAEMON;

mixed cmd(string args) {
  object target;
  string array lans;
  if (angelp(this_player())) return "An angel using the languages command? 
No.";

  if (creatorp(this_player())) {
     if (!args) {
         return "Query languages of whom?";
          }
     target = find_living(args);
    if (!target || (target->GetInvis() && !archp(this_player())) ) {
       return "Unable to find anyone by that name.";
        }
   if(creatorp(target) && target->GetInvis()) {
       return "Unable to find anyone by that name.";
        }
   if (creatorp(target)) {
         return "Lesse... They speak \"ESSENCE\".";
         }
    }
  if (!target) {
     target = this_player();
     }
  lans = target->GetLanguages();
  message("system",
      "Languages Spoken : ",
       this_player() );
    foreach(string val in lans) {
        ShowLanguageMessage(val, target);
        }
  return 1;
  }

void ShowLanguageMessage(string args, object who) {
     string rank;
     int numval;
  numval = who->GetLanguageLevel(args);
  switch (numval) {
     case 0..10:
          rank = "Student";
          break;
     case 11..20:
          rank = "Novice";
          break;
     case 21..30:
          rank = "Broken";
          break;
     case 31..40:
          rank = "Extremely Accented";
          break;
     case 41..50:
          rank = "Badly Accented";
          break;
     case 51..60:
          rank = "Accented";
          break;
     case 61..70:
           rank = "Understandable";
           break;
     case 71..80:
           rank = "Fair";
           break;
     case 81..90:
            rank = "Good";
            break;
    case 91..93:
            rank = "Excellent";
            break;
    case 94..97:
           rank = "Extremely Well";
           break;
    case 98..99:
           rank = "Fluent";
           break;
     case 100:
            rank = "Flawless";
            break;
    default:
            rank = "Unknown";
            break;
        }
  if (args == who->GetNativeLanguage()) {
     rank = "Native";
    }

  message("system", args + " : " + rank + " (" + numval + ")", this_player() );
  }

string GetHelp(string str) {
   return "Syntax: languages\n"
         "Creator Syntax: languages <living>\n"
         "Shows the languages known and a value for the knowledge "
         "of that languages. \n"
        "Ranks are:  Student, Novice, Broken, Extremely Accented, \n"
        "Badly Accented, Accented, Understandable, Fair, Good, \n"
        "Excellent, Extremely Well, Fluent, Flawless.";
   }
