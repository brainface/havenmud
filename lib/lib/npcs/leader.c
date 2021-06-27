/*    /domains/Ylsrim/npc/leader.c
 *    from the Nightmare IVr2 Object Library
 *    class leader inheritable
 *    created by Descartes of Borg 951115
 *    Version: @(#) leader.c 1.4@(#)
 *    Last modified: 97:06:01
 */

#include <lib.h>
#include <daemons.h>
#include <message_class.h>
#include "include/leader.h"

inherit LIB_NPC;
inherit LIB_ADVANCE;
inherit LIB_BOOST_SKILLS;
mapping PlayerTitles;
private string *TaughtSpheres = ({});
private mapping UniqueSkills;
private string *Spells;
private mapping FreeEquip;
int RaceRestricted;
int NoJoin;
int GlobalLeader;
int MultiAllowed;

int eventTeachPlayer(object who, string spell);
varargs int eventTeachSong(object who, string song, int nospam);


static void create() {
  npc::create();
  FreeEquip    = ([ ]);
  MultiAllowed = 1;
  UniqueSkills = ([ ]);
  PlayerTitles = ([ ]);
  SetLimit(1);
}

/* Spiffy Duuk Voodoo 6/16/2017 */

string SetClass(string cl) {
	mapping sk;
	string r = GetReligion();
	if (cl == "priest") {
		sk = MORALITY_D->GetReligionSkills(r);
		UniqueSkills = sk;
	  foreach (string skill, int rank in sk) {
       if (rank)  SetSkill(skill, 1, rank);
       if (!rank) RemoveSkill(skill);
    }		
	}
	return ::SetClass(cl);
}
/*
int SetLevel(int x) {
  mapping mp = UniqueSkills;
	int y = ::SetLevel(x);
	foreach (string skill, int rank in mp) {
     if (rank) SetSkill(skill, (GetLevel()*3)/rank, rank);
     if (!rank) RemoveSkill(skill);
   }
  return y;
}
*/

string *SetReligion(mixed str...) {
	mapping sk;
	string cl = GetClass();
	string rl;
	string *n;
	n = ::SetReligion(str...);
	rl = GetReligion();
	if (cl == "priest") {
		sk = MORALITY_D->GetReligionSkills(rl);
		UniqueSkills = sk;
		foreach (string skill, int rank in sk) {
       if (rank)  SetSkill(skill, 1, rank);
       if (!rank) RemoveSkill(skill);
    }
	}
	return n;
}
/* End Voodoo */


int SetNoJoin(int arg) {return (NoJoin = arg); }

int GetNoJoin() { return (NoJoin); }

int SetGlobalLeader(int arg) {return (GlobalLeader = arg); }

int GetGlobalLeader() {return (GlobalLeader); }

mapping SetPlayerTitles(mapping mp) {
    mapping titles = ([ ]);

    foreach(string key in keys(mp))
    {
if (key == "highmortal" ||
key == "hm")
{
    titles["high mortal"] = mp[key];
}
else
{
    titles[key] = mp[key];
}
    }

    return (PlayerTitles = titles);
}


mapping GetPlayerTitles() {
   return PlayerTitles;
   }

string GetPlayerTitle(string arg) {
   return (PlayerTitles[arg]);
  }

int SetNoMulti(int x) { return MultiAllowed = !x; }

int GetMultiAllowed() { return MultiAllowed; }

int SetRestrictRace(int arg) { return (RaceRestricted = arg); }

int GetRaceRestricted() { return (RaceRestricted); }

void eventGreet(object who) {
  eventForce("speak Hello, " + who->GetCapName() + ", would you like to become " + add_article(GetClass()) + "?");
  eventForce("speak If so, <ask " + GetKeyName() + " to join " + GetClass() + ">");
  if( !who->GetClass() ) {
    eventForce("speak do you mean to ask me to describe " +
       pluralize(GetClass()) + "?");
  }
  eventForce("speak Or to advance a skill or your level?\n");
  eventForce("speak Or to bestow titles you have earned?\n");
  if (GetSkillLevel("faith") || GetSkillLevel("natural magic")){
    eventForce("speak Or perhaps I could convert you to the faith of " + GetReligion() + "?");
  }
      if (GetTaughtSpheres() && GetTaughtSpheres() != ({ }) ){
        eventForce("speak Or I could teach you all spells you are currently able to attempt.");
        eventForce("speak <ask " + GetKeyName() + " to teach all spells>");
      }
      if (GetSkillLevel("vocal music") || GetSkillLevel("instrumental music")) {
        eventForce("speak Or I could teach you all the songs you could possibly perform.");
        eventForce("speak <ask " + GetKeyName() + " to teach all songs>"); 
      }
}

mixed eventAsk(object who, string str) {
    string cmd, args;
    mixed tmp;
    
    if( (tmp = npc::eventAsk(who, str)) == 1 ) return 1;
    if( !str || str == "" ) {
      eventForce("speak ask me to what? To describe " + GetClass() + "s?\n");
      eventForce("speak Or to join "+ GetClass() + "?\n");
      eventForce("speak Or to advance a skill or your level?\n");
      eventForce("speak Or to bestow titles you have earned?\n");
      if (GetSkillLevel("faith") || GetSkillLevel("natural magic")){
eventForce("speak Or perhaps I could convert you to the faith of " + GetReligion() + "?");
      }
      if (GetSkillLevel("vocal music") || GetSkillLevel("instrumental music") || GetTaughtSpheres() ){
eventForce("speak Or I could teach you all spells you are currently able to attempt.");
      }
      return 1;
    }
    if( sscanf(str, "%s %s", cmd, args) != 2 ) {
        cmd = str;
        args = 0;
    }
    switch(cmd) {
        case "describe": case "preview": case "explain":
        eventPreview(who, args);
        break;

       case "bestow": case "grant":
       eventBestowTitles(who, args);
       break;

        case "convert":
        eventConvert(who, args);
        break;

        case "join": case "become": case "be":
        eventJoin(who, args);
        break;

        case "teach":
        eventTeachPlayer(who, args);
        break;
        
        case "advance":  case "train":
        eventAdvance(who, args);
        break;
            
        default:
        eventForce("speak I am not sure what you want");
        if( !who->GetClass() ) {
            eventForce("speak do you mean to ask me to describe " +
                       pluralize(GetClass()) + "?");
        }
eventForce("speak Or to join "+ GetClass() + "?\n");
eventForce("speak Or to advance a skill or your level?\n");
eventForce("speak Or to bestow titles you have earned?\n");
if (GetSkillLevel("faith") || GetSkillLevel("natural magic")){
  eventForce("speak Or perhaps I could convert you to the faith of " + GetReligion() + "?");
}
if (GetSkillLevel("vocal music") || GetSkillLevel("instrumental music") || GetTaughtSpheres() ){
  eventForce("speak Or I could teach you all spells or songs I know that you are currently able to attempt.");
}
        break;
    }
    return 1;
}

void eventConvert(object who, string args) {
  string skill;
  string rel;
  int x;
  rel = who->GetReligion();
  
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
    if (who->GetReligion() != "agnostic" && (who->GetReligion() != GetReligion())) {
  eventForce("speak I am sorry my child, I will only convert you if you"
             " renounce the faith you hold for the " + rel + " religion.");
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

 /* Commented out to Prevent 'weak' conversion of only reset of faith skill 
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
*/
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

void eventParseTitle(object who, string fulltitle) {
string rank, title;
if(sscanf(fulltitle, "%s $N %s", rank, title) == 2) {
who->AddRank(rank); who->AddTitle(title);
}
else who->AddTitle(fulltitle);
}

void eventBestowTitles(object who, string args) {
   if (!args) {
     eventForce("speak What would you like me to bestow upon you?");
     return;
     }
  if ((args != "titles") && (args != "title")) {
      eventForce("speak I cannot bestow that upon you.");
      eventForce("speak People only ask me to bestow titles.");
     return;
     }
  if ((who->GetTown() != GetTown()) && !(GetGlobalLeader())) {
     if (GetTown() == "the Heavens") {
       eventForce("speak I am unable to bestow titles");
       return;
       }
     eventForce("speak I only grant titles to people from " + GetTown());
     return;
    }

  if (!(who->ClassMember(GetClass()))) {
     eventForce("speak I only deal with " + pluralize(GetClass()) + " here.");
     return;
     }
  if (GetReligion() && GetReligion() != "agnostic") {
     if (!(who->GetReligion() == GetReligion())) {
       eventForce("speak I only deal with people of my faith.");
       return;
      }
    }
  if (GetRaceRestricted() && (who->GetRace() != GetRace()) ) {
    eventForce("speak I only deal with " + pluralize(GetRace()) );
    return;
    }
  foreach(string class_title in keys(GetPlayerTitles())) {
    if (who->ClassMember(class_title)) {
       eventForce("speak You are entitled to the name " + GetPlayerTitle(class_title) );
       eventParseTitle(who, GetPlayerTitle(class_title));
       }
    }
    if (GetPlayerTitle("newbie")) {
    eventForce("speak You are entitled to be called " + GetPlayerTitle("newbie") );
    eventParseTitle(who, GetPlayerTitle("newbie"));
   }
    if (!newbiep(who) && GetPlayerTitle("mortal")) {
        eventForce("speak You are entitled to be called " + GetPlayerTitle("mortal") );
        eventParseTitle(who, GetPlayerTitle("mortal"));
        }
    if (high_mortalp(who) && GetPlayerTitle("high mortal")) {
        eventForce("speak You are entitled to be called " + GetPlayerTitle("high mortal") );
        eventParseTitle(who, GetPlayerTitle("high mortal"));
        }
   if (legendp(who) && GetPlayerTitle("legend")) {
        eventForce("speak You are entitled to be called " +  GetPlayerTitle("legend"));
        eventParseTitle(who, GetPlayerTitle("legend"));
        }
   if (avatarp(who) && GetPlayerTitle("avatar")) {
        eventForce("speak You are entitled to be called " + GetPlayerTitle("avatar") );
        eventParseTitle(who, GetPlayerTitle("avatar"));
      }
   return;
 }

int CanBoost() {
  if (GetSkillClass("conjuring")) return 1;
  if (GetSkillClass("natural magic")) return 1;
  if (GetSkillClass("faith")) return 1;
  if (GetSkillClass("vocal music")) return 1;
  if (GetSkillClass("instrumental music")) return 1;
  return 0;
}    

void eventPreview(object who, string args) {
    string *tmp = ({ });
    if( args ) args = remove_article(lower_case(args));
    if( args && args != "" && args != GetClass() ) {
        if( args[0..<2] != GetClass() ) {
            eventForce("speak You want me to describe what?");
            return;
        }
    }
    who->eventPrint(HELP_D->GetHelp(GetClass()));
    foreach(string sk in (keys(UniqueSkills))) {
      switch (UniqueSkills[sk]) {
        case 0:
          tmp += ({ sk + " (removed)" });
          break;
        case 1:
          tmp += ({ sk + " (primary)" });
          break;
        case 2:
          tmp += ({ sk + " (secondary)" });
          break;
        case 3..5:
          tmp += ({ sk + " (other)" });
          break;
        default:
          tmp += ({ sk + " (" + UniqueSkills[sk] + ")" });
          break;
        }
      }
    if (GetBoostSkill(who->GetNationality(), who) && CanBoost()) tmp += ({ GetBoostSkill(who->GetNationality(), who) + " (secondary)" });
    //mahkefel--for wilderness dudes in particular, making them get the player's towns boostskill.
    if (sizeof(tmp))
      eventForce("speak If you use me to join " + GetClass() + " you will also receive "
                 "the following unique skill set: " + conjunction(tmp, "and"));
}

void eventJoin(object who, string args) {
  object equip;
  string tmp;
  if (who->GetNationality() != GetTown() && GetTown() != "all" && !GlobalLeader) {
    eventForce("speak Sorry, I only deal with people born in " + GetTown());
    return;
  }
  if( GetNoJoin() ) {
    eventForce("speak Sadly, I cannot accept any new trainees "
      "at this time.");
    return;
  }
  if( !args || args == "" ) {
    eventForce("speak Do you mean you wish to become " + add_article(GetClass()) + "?");
    return;
  }
  args = remove_article(lower_case(args));
  if( args != GetClass() && args[0..<2] != GetClass() && args != pluralize(GetClass()) )
  {
    eventForce("speak you want me to make you a what?");
    eventForce("speak people only ask me to join the " + pluralize(GetClass()));
    return;
  }
  if (who->GetClass() && (!(GetMultiAllowed()) || !(who->GetMultiAllowed()))) {
    eventForce("speak I am sorry, but I cannot allow that.");
    return;
  }
  if( (int)who->ClassMember(GetClass()) ) {
    eventForce("speak You are already " + add_article(GetClass()));
    return;
  }
  if (GetReligion() != "agnostic" && (who->GetReligion(0) != GetReligion(0) ) ) {
    eventForce("speak Only members of my faith may become " + pluralize(GetClass()));
    return;
  }
  foreach(string sk in GetSkills()) {
    if (SKILLS_D->CheckRestrictedSkill(sk, who->GetSkills())) {
    eventForce("speak One of your skills prevents you from learning " + sk);
    return;
    }
  }
  if (who->GetClass()) {
    if (who->GetDevelopmentPoints() < 100) {
      eventForce("speak You are not prepared to multiclass.");
      who->eventPrint("You must have 100 development points for that.");
      return;
    }
  }
  if (who->GetDevelopmentPoints() < 160 && !(who->GetClass())) {
    eventForce("speak You are not able to join a class.");
    who->eventPrint("You must have 160 development points for that.");
    return;
  }

  // this makes them the class! this final if loop! right here!
  if( (string)who->GetClass() == (string)who->SetClass(GetClass()) ) {
    eventForce("speak You cannot become " + add_article(GetClass()) + "!");
    return;
  }

  if (GetClass() == "vampire") {
    send_messages("bite", "%^RED%^$agent_name $agent_verb $target_name on the neck "
      "and quickly sucks all $target_possessive_noun blood out. What did "
      "$target_nominative expect?%^RESET%^", this_object(), who, environment(who) );
      who->SetUndead(1);
      who->SetUndeadType("vampire");
  }
  environment()->eventPrint(GetName() + 
    " makes " + (string)who->GetName() + " " + add_article(GetClass()) + ".",
    ({ who, this_object() }));
  eventForce("speak Congratulations new " + GetClass() + "!");
  if (who->GetClass() != GetClass()) who->AddDevelopmentPoints(-100);
  else who->AddDevelopmentPoints(-160);
  eventBestowTitles(who, "titles");
  if (sizeof(GetFreeEquip())) {
    foreach(string thing in keys(GetFreeEquip())) {
      for (int x = 0; x < FreeEquip[thing]; x++) {
        equip = new(thing);
        if (equip) {
          equip->eventMove(who);
          eventForce("speak Here is a new " + equip->GetKeyName() + " for you.");
        }
       }
     }
   }
  if (!GetMultiAllowed()) who->SetNoMulti(1);
  if (sizeof(keys(GetUniqueSkills()))) {
    foreach(string skill, int rank in GetUniqueSkills()) {
      int cLevel, cRank;
      cLevel = who->GetSkillLevel(skill);
      cRank  = who->GetSkillClass(skill);
      if (rank < cRank || !cRank) who->SetSkill(skill, cLevel || 1, rank);
      if (rank && who->GetLevel() < 2) who->SetSkill(skill, cLevel || 1, rank);
      if (!rank && cLevel < 2) who->RemoveSkill(skill);
      }   
    }
  eventForce("speak Go see the town youth equipper for more help!");
  if ((tmp = GetBoostSkill(who->GetNationality(), who)) && CanBoost()) {
     if (who->GetTestChar()) debug("test " + tmp);
      if (!who->GetSkillLevel(tmp) && tmp) who->SetSkill(tmp, 0, 2);
      }
  who->SetShort("foo");  /* reset title */
  CHAT_D->eventSendChannel("Joined Class", "reports", 
           capitalize(who->GetKeyName()) + " joined " +
           pluralize(GetClass()) + " (" + who->GetClass() + ")");
   return;
}


varargs int eventTeachPlayer(object who, string spell, int nospamflag) {
  string *spheres = GetTaughtSpheres();
  object ob = SPELLS_D->GetSpell(spell);
  string *learn = ({ });
  if (!environment()) return 0;
  if (spell == "all spells") {
    foreach(string sph in GetTaughtSpheres()) {
      
      foreach(string sp in SPELLS_D->GetSphereSpells(sph)) {
      
        if ((SPELLS_D->GetSpell(sp))->GetUniqueSpell()) continue;
        if (!who->GetSpellLevel(sp)) { 
      
          eventTeachPlayer(who, sp, 1); 
          if (who->GetSpellLevel(sp)) learn += ({ sp }); 
          }
        } 
    } 
    if (who != this_object()) {
      if (sizeof(learn) <= 25 && sizeof(learn)) {  eventForce("speak I taught you " + conjunction(learn, "and")); }
      if (sizeof(learn) > 25 )  eventForce("speak I taught you an excessive number of spells.");
      if (!sizeof(learn))  eventForce("speak You are not prepared to learn any new magic.");
      }
    return 1;
  }
  if (spell == "all songs") {
    foreach(string sp in SONGS_D->GetSongs()) {
        if (resolve_song_type(base_name(SONGS_D->GetSong(sp))) != "test songs" && !(who->GetSongLevel(sp)) ) {
          eventTeachSong(who, sp, 1);
          if (who->GetSongLevel(sp)) learn += ({ sp }); 
          }
       }
    if (who != this_object()) {
      if (sizeof(learn) <= 25 && sizeof(learn)) eventForce("speak I taught you " + conjunction(learn, "and"));
      if (sizeof(learn) > 25 ) eventForce("speak I taught you an excessive number of songs.");
      if (!sizeof(learn)) eventForce("speak You are not prepared to learn any new music.");          
     }
    return 1;
  }
  if (!ob && spell) {
    if(ob = SONGS_D->GetSong(spell)) {
       return eventTeachSong(who, spell);
     }
  eventForce("speak I'm sorry, I don't know that magic.");
  return 1;
  }

  if (!sizeof(GetTaughtSpheres()) && !ClassMember("bard") && !ClassMember("dancer")) {
    eventForce("speak Uhhhhhhhhhhh, I don't teach magic.");
    eventForce("emote looks confused.");
    if (sizeof(GetSpellBook()) || sizeof(GetSongBook()) ) {
      CHAT_D->eventSendChannel(GetName(), "error", GetName() + 
                               " is non compliant with Spheres.", 1);
      CHAT_D->eventSendChannel(GetName(), "error", file_name(
this_object()), 1);
      }
    return 1;
    }
  if (ClassMember("bard")) {
    eventForce("speak I teach music and songs.");
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
  if (GetReligion() && (who->GetReligion() != GetReligion()) && GetReligion() != "agnostic") {
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

varargs int eventTeachSong(object who, string song, int nospamflag) {
  object ob = SONGS_D->GetSong(song);

  if (resolve_song_type(base_name(ob)) == "test songs" && !who->GetTestChar()) {
    return 1;
    }
  if (GetReligion() && (who->GetReligion() != GetReligion()) && GetReligion() != "agnostic") {
    eventForce("speak I only teach people of my own faith!");
    return 1;
    }
  if (ob->GetUniqueSong() && !GetSongLevel(song)) {
    eventForce("speak I'm afraid I don't know that song.");
    return 1;
    }
  if (!(who->eventLearnSong(song))) {
    if (!nospamflag) 
      eventForce("speak You are not prepared to perform " + song + "!");
    return 1;
    }
  send_messages("teach",
    "$agent_name $agent_verb $target_name " + song + ".",
    this_object(), who, environment() );
  return 1;
  }

mapping SetFreeEquipment(mapping mp) {
   return (FreeEquip = mp);
  }

mapping SetFreeEquip(mapping mp) {
  return SetFreeEquipment(mp);
}

mapping GetFreeEquip() {
  return (FreeEquip);
  }

mapping SetUniqueSkills(mapping mp) {

/*  This was commented out so the fancy new UniqueSkils stuff will work
 *  without needing to worry about any NPCs that use UniqueSkills.

   foreach (string skill, int rank in mp) {
     if (rank)
      SetSkill(skill, (GetLevel()*3)/rank, rank);
     if (!rank) RemoveSkill(skill);
     }
   return (UniqueSkills = mp);
*/

   return UniqueSkills;
}

mapping GetUniqueSkills() {
   return (UniqueSkills);
}

mapping AddUniqueSkill(string sk, int rank) {
	UniqueSkills += ([ sk : rank ]);
	return UniqueSkills;
}

mapping AddUniqueSkills(mapping m) {
  UniqueSkills += m;
  return UniqueSkills;
}


static void SetSpellBook(mapping mp) {
  if (sizeof(keys(mp)) > 20) return;
  npc::SetSpellBook(mp);
  Spells = keys(mp);
}

mapping SetSongBook(mapping mp) {
    npc::SetSongBook(mp);
    Spells = keys(mp);
}

string *SetTaughtSpheres(string *spheres) {
  /* This is going to be a useless function.
   * Removing it will fix all the NPCs that 
   * Don't seem to teach the right stuff.
   */  
  return TaughtSpheres = spheres;
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

  if (GetSkillLevel("practical magic")) {
    str += ({ "practical" });
  }  
  if (GetSkillLevel("vampirism")) {
    str += ({ "vampirism" });
  }  
  if (GetReligion() != "agnostic") 
    str += ({ "religion " + lower_case(GetReligion()) });
  return str;
}

