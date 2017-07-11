#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

/* This daemon makes uses of a string array in the player object
 * called "LongDaemonData". This is where all the useful stuff
 * will be stored, and will vary by race as to what data needs
 * to be stored.  
 * Primarily, this will include hair color, eye color, skin 
 * tone, height, body shape, any descriptive features such as
 * pointy ears, etc.
 * data[0] = eyes
 * data[1] = hair
 * data[2] = skin
 * data[3] = skin description
 * data[4] = extra data
 */

string GetStrengthSentence(object who, string nom, string pos) {
	int str = who->GetStatLevel("strength");
	string tmp = "";
	switch(str) {
		case 0..15:
		  tmp += pos + " body is flaccid and weak in appearance.";
		  break;
		case 16..20:
		  tmp += pos + " body is thin and scrawny.";
		  break;
		case 21..35:
		  tmp += nom + " looks as strong as an average human.";
		  break;
		case 36..45:
      tmp += pos + " body is fit and healthy.";
      break;
    case 46..60:
      tmp += pos + " body appears to be sturdy and well formed.";
      break;
    case 61..75:
      tmp += nom + " appears to be very strong and well built.";
      break;
    case 76..90:
      tmp += nom + " is a large, powerfully built " + who->GetRace() + ".";
      break;
    case 91..100:
      tmp += nom + " is ripped with bulging muscle.";
      break;
    case 101..124:
      tmp += nom + " has muscles that defy description.";
      break;
    case 125..200:
      tmp += nom + " has a physique of hard, bulging muscles that rival the roots " +
             "of large trees.";
      break;
    default:
      tmp += nom + " has an issue that prevents a true gauge of strength.";
      break;
   }
  return capitalize(tmp);
}

string GetCharismaSentence(object who, string nom, string pos) {
	int str = who->GetStatLevel("charisma");
	int g;
	string tmp = "";
	if (who->GetGender() == "female") g = 1;
	switch(str) {
		case 0..5:
		  tmp += pos + " face is repulsive.";
		  break;
		case 6..10:
		  tmp += pos + " face is plain and ugly.";
		  break;
		case 11..20:
		  tmp += pos + " face is unpleasant to view.";
		  break;
		case 21..35:
      tmp += pos + " face is fairly typical.";
      break;
    case 36..50:
      tmp += pos + " face is " +(g ? "pretty" : "handsome") + " but not memorable.";
      break;
    case 51..75:
      tmp += nom + " is very attractive, beautiful to anyone of any race.";
      break;
    case 76..90:
      tmp += nom + " is a stunning specimen of beauty.";
      break;
    case 91..100:
      tmp += nom + " is a gorgeous work of lovely charm and beauty.";
      break;
    case 101..124:
      tmp += nom + " has dazzling looks that could tame all but the fiercest creatures.";
      break;
    case 125..200:
      tmp += pos + " looks rival the Goddess of Soirin in raw beauty. " + capitalize(nom) +
                   " stops all conversation with a glance and with a wink can send troops " +
                   "to fight and die. " + capitalize(pos) + " charisma cannot be overstated.";
      break;
    default:
      tmp += nom + " has an issue that prevents a true gauge of beauty.";
      break;
   }
  return capitalize(tmp);
}

string GetMentalSentence(object who, string nom, string pos) {
	int str = who->GetStatLevel("intelligence");
	int wis = who->GetStatLevel("wisdom");
	int g;
	string tmp = "";
	if (who->GetGender() == "female") g = 1;
	switch(str) {
		case 0..5:
		  tmp += nom + " has the look of a complete idiot plasted on their face.";
		  break;
		case 6..10:
		  tmp += nom + " has the look of a child lost in an adult world.";
		  break;
		case 11..20:
		  tmp += nom + " seems to be not terribly bright.";
		  break;
		case 21..35:
      tmp += nom + " seems to be of average intellect.";
      break;
    case 36..50:
      tmp += nom + " has " + add_article((str > wis ? "intelligent" : "wise")) + " look upon " +
                   pos + " face.";
      break;
    case 51..75:
      tmp += nom + " gives off an appearance of confident intellect.";
      break;
    case 76..90:
      tmp += nom + " has a powerfully deep gaze of intelligence.";
      break;
    case 91..100:
      tmp += nom + " seems to have an aura of brilliance surrounding " + objective(who) + ".";
      break;
    case 101..124:
      tmp += nom + " has a deeply pensive gaze capable of ensnaring those of weak will.";
      break;
    case 125..200:
      tmp += pos + " gaze has the deep quality of someone who has not only contemplated " +
                    pos + " own existance relative to the Gods, but has come away with "
                    "a deep understanding of the divine plan of existance.";
      break;
    default:
      tmp += nom + " has an issue that prevents a true gauge of intelligence.";
      break;
   }
  return capitalize(tmp);
}

string GetScars(object who, string nom, string pos) {
	int scars = sizeof(who->GetDeaths());
	if (!scars) {
		return capitalize(pos) + " skin is unmarred and bears no scars.";
	}
	return capitalize(pos) + " skin is marred by " + cardinal(scars) + 
	                         (scars > 1 ? " scars." : " scar.");
}

string GetExtraSentence(object who, string nom, string pos, string extra) {
	string tmp = extra;
	
	tmp = replace_string(tmp, "$POS", pos);
	tmp = replace_string(tmp, "$NOM", nom);
	tmp = replace_string(tmp, "$OBJ", objective(who->GetGender()));
	return tmp;
}

string GetLong(object who) {
  string race = who->GetRace();
  string *data;
  string tmp = "";
  string nom = nominative(who);
  string pos = possessive(who);
  string cap = who->GetCapName();
  data = allocate(5);
  data = who->GetLongDaemonData();
  tmp = cap + " is a " + who->GetGender() + " " + race;
  if (data[0]) tmp += ". " + capitalize(nom) + " has " + data[0] + " eyes";
  if (data[0] && !data[1]) tmp += ".";
  if (data[0] && data[1])  tmp += " and"; 
  if (data[1] && !data[0]) tmp += ". " + capitalize(nom);
  if (data[1]) tmp += " has " + data[1] + " hair.";
  if (!data[0] && !data[1]) tmp += ".";
  if (data[2] && data[3]) tmp += " " + capitalize(pos) + " " + data[3] + " body has " +
                            add_article(data[2]) + " color.";
  if (data[4]) tmp += " " + cap + " has " + GetExtraSentence(who, nom, pos, data[4]); 
  tmp += " " + capitalize(nom) + " has a " + 
               who->GetMoralityDescription(who->GetStatLevel("charisma") * 10) + 
               " look on " + pos + " face.";                
  tmp += " " + GetStrengthSentence(who, nom, pos);
  tmp += " " + GetCharismaSentence(who, nom, pos);
  tmp += " " + GetMentalSentence(who, nom, pos);
  tmp += " " + GetScars(who, nom, pos);
  return tmp;
}

varargs string *SetLongData(object who, mixed data...) {
	string *d = ({ });
	if (!arrayp(data)) data = ({ data });
	if (sizeof(data) < 5) {
		data = data + ({ 0, 0, 0, 0, 0 });
		}
	return who->SetLongDaemonData(data);
}

