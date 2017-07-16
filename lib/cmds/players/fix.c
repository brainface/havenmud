// The 'fix' command
// Allows players to fix broken stuff all by themself!
// Created by Zaxan@Haven
//

#include <lib.h>
#include <std.h>
#include <daemons.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

static void create() {
   help::create();
   SetHelp("Syntax: fix <see below>\n" 
           "This command is useful for fixing many problems. \n\n"
           "<ring> Restore lost wedding rings. Note you must have a "
             "spouse for this to work. \n\n"
           "<skills> Fix any skills that are at a negative level. \n"
           "         Also fixes \"lockpicking\" issue.\n\n"
           "<room> Fix a room that doesn't have any exits "
             "due to a bug. \n\n"
           "<spells> Remove any spells from your spell book that have "
             "been renamed or removed. Note that if a spell has been "
             "renamed, you must relearn it.\n\n"
           "<songs> Remove any songs from your song book that have "
             "been renamed or removed. Note that if a song has been "
             "renamed, you must relearn it.\n\n"
           "<ships> Reload any ships you own. \n\n"
           "<nationality> Set your nationality to your current town. \n\n"
           "<description> Reset your description to the racial base.\n\n"
           "<guild> Restore a lost guild object.\n"
           "<title> Resets your title for those times something is weird.\n"
           "<estate> Reloads player estates.\n"
                  );
}

mixed cmd(string args) {
   object who = this_player();
   object tmp = 0;
   string str = 0;
   string *spell_list = ({});
   int ti;
   
   switch(args) { 
     case "oocname":
       if (who->GetEmail() == "fuzzydemon84@hotmail.com")
         who->SetOOCName("john");
       who->eventPrint("Checked!");
     break;
     case "title":
       who->SetShort("");
       who->eventPrint("Fixified!");
       break;
     case "ring":
       tmp = new(STD_OBJ "wed_ring");
       str = who->GetSpouse();
       if(!str) {
         return "You are not married!";
         }
       if(!tmp) {
         return "Problem restoring your ring, please contact an Arch.";
         }
       if(present("wedding ring", who)) {
         return "You already have a wedding ring!";
         }
       tmp->SetSpouse(str);
       tmp->eventMove(who);
       return "Your wedding ring has been replaced.";
       break;
     case "skills":
       foreach(string skill in who->GetSkills()) {
         if(who->GetSkillLevel(skill) < 0) {
            who->SetSkill(skill, 0, who->GetSkillClass(skill));
         }
       }
      if (ti = who->GetSkillClass("lock-picking")) {
        who->SetSkill("lockpicking", who->GetSkillLevel("lock-picking"), ti);
        who->RemoveSkill("lock-picking");
        }
      if (ti = who->GetSkillClass("multi-hand")) {
        who->RemoveSkill("multi-hand");
      }
      return "Your skills have been fixed.";
      break;
     case "room":
      str = base_name(environment(who));
      if(environment(who)->GetProperty("no exits")) {
         return "This room is not bugged.";
      }
      if( (sizeof(environment(who)->GetExits())) ||
          (sizeof(environment(who)->GetEnters())) ) {
         return "This room is not bugged.";
      }
      unguarded((: log_file, "adm/exits", capitalize(who->GetKeyName()) +
                   " had "+ str +" fixed on "+ctime(time())+".\n" :));
      environment(who)->eventDestruct();
      who->eventMove(str);
      return "Exits repaired.";
      break;
    case "spells": 
       spell_list = SPELLS_D->GetSpells();
       foreach(string spell in keys(who->GetSpellBook())) {
               if (member_array(spell, spell_list) == -1) {
                 who->eventForgetSpell(spell);
                 }
         }
       return "Your spells have been fixed.";
       break;
    case "songs": 
       spell_list = SONGS_D->GetSongs();
       foreach(string spell in keys(who->GetSongBook())) {
               if (member_array(spell, spell_list) == -1) {
                 who->eventForgetSong(spell);
                 }
         }
       return "Your songs have been fixed.";
       break;
    /*case "ships":
      VEHICLES_D->PlayerLogin(who);
      return "Fixing ships has been temporarily disabled.  Logout and on!";
      break; */
    case "nationality":
      if (who->GetNationality()) {
        return "You already have a nationality.  It cannot be changed.";
      }
      who->SetNationality(who->GetTown());
      who->SetShort("");
      return "Your nationality has been set.";
      break;
    case "description":
      if (sizeof(who->GetLongDaemonData())) {
        return "Sorry, your description cannot be altered.";
        }
      DESCRIPTION_D->SetLongData(who);
      return "Your description is fixed.";
      break;
    case "religion":
      if (who->GetReligion() == "Troism") who->SetReligion("Eclat", "Eclat");
      who->eventPrint("Religion set to " + who->GetReligion() + ".");
      return 1;
      break;
    case "guild":
      foreach(object o in all_inventory(who)) {
        if (o->GetGuildObject()) o->eventDestruct();
        }
      if (!who->GetGuild())  return "You are not in a guild!";
      if (!tmp = new(STD_GUILD + who->GetGuild())) return "Could not load guild object.";
      tmp->eventMove(who);  
      tmp->eventPrint("Fixed.");
      return 1;
      break;
    case "estate": case "estates":
      ESTATE_D->LoadEstates();
      return "Estates reloaded.";
      break;
    default:
      return "Fix what?  See \"help fix\"";
      break;
    }
  return "Wtf?";
}
