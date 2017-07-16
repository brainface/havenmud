/*  A magic trainer 
 *  Saryt
 *  eventConvert rewritten by Laoise, March 2005
 *  Now works the same as trainer.
 */

#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;
string *TaughtSpheres;
int RaceRestricted;

static void create() {
	::create();
	TaughtSpheres = ({});
  RaceRestricted = 1;
  SetLimit(1);
  SetClass("merchant");
}

int SetRaceRestricted(int x) { return RaceRestricted = 1; }

int GetRaceRestricted() { return RaceRestricted; }

string *SetTaughtSpheres(string *x) { 
	if (!arrayp(x)) x = ({ x });
	return TaughtSpheres = x; 
}

string *GetTaughtSpheres() {
  string *str = ({});
  if (GetSkillLevel("evokation")) {
    str += ({ "evokation" });
  }
  if (GetSkillLevel("enchantment")) {
    str += ({ "enchantment" });
  }  if (GetSkillLevel("necromancy")) {
    str += ({ "necromancy" });
  }
    if (GetSkillLevel("illusion")) {
    str += ({ "illusion" });
  }

  if (GetSkillLevel("faith")) {
  	str += ({ "faith" });
  	if (GetSkillLevel("necromancy"))
  	  str += ({ "faith necromancy" });
  	if (GetSkillLevel("healing"))
  	  str += ({ "faith healing" });
  	if (GetSkillLevel("enchantment")) 
  	  str += ({ "faith enchantment" });
  	if (GetSkillLevel("evokation"))
  	  str += ({ "faith evokation" });
  	}
  if (GetSkillLevel("conjuring")) {
  	str += ({ "conjuring" });
  	if (GetSkillLevel("necromancy"))
  	  str += ({ "conjuring necromancy" });
  	if (GetSkillLevel("healing"))
  	  str += ({ "conjuring healing" });
  	if (GetSkillLevel("enchantment")) 
  	  str += ({ "conjuring enchantment" });
  	if (GetSkillLevel("evokation"))
  	  str += ({ "conjuring evokation" });
  	}
  if (GetSkillLevel("natural magic")) {
  	str += ({ "natural" });
  	if (GetSkillLevel("necromancy"))
  	  str += ({ "natural necromancy" });
  	if (GetSkillLevel("healing"))
  	  str += ({ "natural healing" });
  	if (GetSkillLevel("enchantment")) 
  	  str += ({ "natural enchantment" });
  	if (GetSkillLevel("evokation"))
  	  str += ({ "natural evokation" });
  	}
  if (GetReligion() != "agnostic") 
    str += ({ "religion " + lower_case(GetReligion()) });		
  return str;
}

void eventGreet(object who) {
  eventForce("speak Hello! I could possibly convert you or teach you spells. Just <ask>");
}
  

void eventConvert(object who, string args) {
  string skill;
  int x;
// Check if leader has ability to do conversions
  if (!GetSkillLevel("faith") && member_array(GetClass(), ({ "mystic", "druid" }) ) == -1) {
    eventForce("speak I don't do conversions");
    return;
  }
 // Player code
  if (!args || args == "") {
    eventForce("speak convert whom?");
    return;
  }
  if (args != "me") {
    object ob;

    ob = present(args, environment());
    if (!ob) {
      eventForce("speak I don't see any such thing here");
      return;
    }
    if (!living(ob)) {
      eventForce("laugh");
      eventForce("speak would like to worship some cheese too?");
      return;
    }
    if (ob != who) {
      eventForce("speak " + (string)ob->GetName() + " must request "
      "conversion of " + possessive(ob) + " own free will.");
      return;
    }
  }
  if (who->GetProperty("faithless")) {
    eventForce("speak Your faithlessness in the past causes me to doubt "
    "your intention. You cannot convert without divine intervention.");
    return;
  }
  if (who->GetReligion() == GetReligion()) {
    eventForce("speak You are already one of us, little one.");
    return;
  }
  if (who->GetReligion() == "agnostic") {
    eventForce("speak Welcome to our faith, "+who->GetCapName());
    log_file("faith",
    who->GetCapName() + " has betrayed the faith of " +
    who->GetReligion() + ", forsaking it for " + GetReligion() +
    ".\n" + ctime(time()) + "\n");
  CHAT_D->eventSendChannel(who->GetCapName(), "prayer",
    who->GetCapName() + " has forsaken the religion of " + 
    who->GetReligion() + " to follow the " +
    GetReligion() + " faith.", 1);
    who->SetReligion(GetReligion(0),GetReligion(1));
    MORALITY_D->SetBaseMorality(who);
    return;
  }
  if ((who->GetReligion() == "Eclat" && who->GetSkillLevel("natural magic")) 
    || (who->GetSkillLevel("faith"))) {
    who->eventPrint("%^YELLOW%^You feel pain at the loss of your Diety.%^RESET%^");
    foreach(skill in who->GetSkills()) {
      x = random(40 - who->GetSkillClass(skill))/2;
      while( x-- )
      who->AddSkillPoints(skill, -who->GetMaxSkillPoints(skill,
      who->GetBaseSkillLevel(skill)));
    }
    foreach(string title in who->GetTitles()) {
      who->RemoveTitle(title);
    }
  }
  if (who->GetReligion() == "Eclat" && who->GetSkillLevel("natural magic")) {
    who->SetSkill("natural magic", 0);
  } else {
    if (who->GetSkillLevel("faith")) {
      who->SetSkill("faith", 0); 
    } else {
      who->eventPrint("%^YELLOW%^You feel pain at the loss of your Diety.%^RESET%^");
      foreach(skill in who->GetSkills()) {
        x = random(20 - who->GetSkillClass(skill))/2;
        while( x-- )
        who->AddSkillPoints(skill, -who->GetMaxSkillPoints(skill,
        who->GetBaseSkillLevel(skill)));
      }
    }
  }
  eventForce("speak Welcome to our faith, "+who->GetCapName());
  log_file("faith",
    who->GetCapName() + " has betrayed the faith of " +
    who->GetReligion() + ", forsaking it for " + GetReligion() +
    ".\n" + ctime(time()) + "\n");
  CHAT_D->eventSendChannel(who->GetCapName(), "prayer",
    who->GetCapName() + " has forsaken the religion of " + 
    who->GetReligion() + " to follow the " +
    GetReligion() + " faith.", 1);
  who->SetReligion(GetReligion(0),GetReligion(1));
  who->SetPermanentProperty("faithless", 1);
}

varargs int eventTeachPlayer(object who, string spell, int nospamflag) {
  string *spheres = GetTaughtSpheres();
  string *learn = ({ });
  object ob = SPELLS_D->GetSpell(spell);
  if (spell == "all spells") {
    foreach(string sph in GetTaughtSpheres()) {     
      foreach(string sp in SPELLS_D->GetSphereSpells(sph))  {
         if ((SPELLS_D->GetSpell(sp))->GetUniqueSpell()) continue;
         if (!who->GetSpellLevel(sp)) { 
            eventTeachPlayer(who, sp, 1); 
            if (who->GetSpellLevel(sp)) learn += ({ sp }); 
         }
      }
    }
  if (sizeof(learn) <= 25 && sizeof(learn)) eventForce("speak I taught you " + conjunction(learn, "and"));
  if (sizeof(learn) > 25 ) eventForce("speak I taught you an excessive number of spells.");
  if (!sizeof(learn)) eventForce("speak You are not prepared to learn any new magic.");
    return 1;
  }
  if (!ob && spell) {
    eventForce("speak I'm sorry, I don't know that magic.");
    return 1;
  }

  if (!sizeof(GetTaughtSpheres())) {
    eventForce("speak Uhhhhhhhhhhh");
    eventForce("emote looks confused.");
    if (sizeof(GetSpellBook())) {
      CHAT_D->eventSendChannel(GetName(), "error", GetName() + 
                               " is non compliant with Spheres.", 1);
      CHAT_D->eventSendChannel(GetName(), "error", file_name(this_object()), 1);
      }
    return 1;
    }
  if (!spell) {
       eventForce("speak I teach from the spheres:");
       eventForce("speak " + conjunction(GetTaughtSpheres()) );
       return 1;
     }
  if(member_array(SPELLS_D->GetSpellSphere(spell), spheres) == -1) {
    eventForce("speak I don't know that spell.");
    eventForce("speak I only teach spells from the spheres: ");
    eventForce("speak " + conjunction(GetTaughtSpheres(), "and"));
    return 1;
  }
  if(ob->GetUniqueSpell() && !GetSpellLevel(spell)) {
      eventForce("speak I'm afraid I don't teach that spell.");
      return 1;
     }
  if (GetReligion() && (who->GetReligion() != GetReligion() 
      && GetReligion() != "agnostic") ) {
  eventForce("speak I only teach people of my own faith!");
  return 1;
  }
  if (who->eventLearnSpell(spell)) {
      send_messages( ({ "teach" }),
         "$agent_name $agent_verb $target_name " + spell + ".",
          this_object(), who, environment() );
       return 1;
     } else {
        if (!nospamflag) eventForce("speak You are not prepared to learn " + spell + "!");
        return 1;
      }
}

int eventAsk(object who, string str) {
	 string cmd, args;
    mixed tmp;
    
    if( (tmp = npc::eventAsk(who, str)) == 1 ) return 1;
    if( !str || str == "" ) {
        eventForce("speak ask me to what? To teach talents?");
        eventForce("speak Or would you like me to convert you?");
        return 1;
    }
    if( sscanf(str, "%s %s", cmd, args) != 2 ) {
        cmd = str;
        args = 0;
    }
   if (who->GetReputation(GetTown()) < -100) {
    	eventForce("speak Why would I aid someone as disliked as you?");
    	return 1;
    }
   switch(cmd) {
        case "convert":
        eventConvert(who, args);
        break;

        case "teach":
        eventTeachPlayer(who, args);
        break;
            
        default:
        eventForce("speak I am not sure what you want");
        if( who->GetClass() ) {
           eventForce("speak Would you please speak sensibly?");
        }
        else {
            eventForce("speak do you mean to ask me to convert you?");
        }
        break;
    }
    return 1;
}
