/*    /lib/magic.c
 *    From Dead Souls LPMud
 *    A module for allowing living beings to cast magic spells.
 *    Created by Descartes of Borg 961027
 *    Version: @(#) magic.c 1.13@(#)
 *    Last modified: 96/11/03
 */

#include <daemons.h>
#include <rounds.h>
#include <magic.h>
#include <music.h>
#include <armour_types.h>

private mapping SpellBook = ([]), SongBook = ([]);
private int RecoveryTime, NoSing;

// abstract methods
mixed *AddSave(mixed array x) { return x; }
int GetInCombat();
int GetMagicPoints();
int GetHealthPoints();
string GetName();
int GetParalyzed();
varargs mixed eventPrint(string msg, mixed args...);
int GetSkillLevel(string skill);
int GetStaminaPoints();
int SetRecoveryTime(int);
int GetRecoveryTime();
int AddRecoveryTime(int);
void SetAttack(object array e, function f, int type);
string GetReligion();
string GetCombatStyle();
int GetSleeping();
object *GetUniqueWorn();
int AddExperience(int);
// end abstract methods

static varargs void eventCast(object spell, string limb, object array targs);
static void eventTrainSpell(object spell);

static varargs void eventSing(object song, string limb, object array targs);
mixed eventForgetSong(string song);
varargs void eventTrainSong(object song, int num);


int AddRecoveryTime(int x) {
	return RecoveryTime += x;
}

int SetRecoveryTime(int x) {
	return RecoveryTime = x;
}

int GetRecoveryTime() { return RecoveryTime; }
mapping GetSpellBook() {
    return copy(SpellBook);
}

void ResetMagicBooks() {
  SpellBook = ([ ]);
  SongBook  = ([ ]);
  debug("All magic reset in " + base_name(this_object()));
}

static void SetSpellBook(mapping book) {
    SpellBook = book;
}

int GetSpellLevel(string sp) {
  int x;
  object spell = SPELLS_D->GetSpell(sp);
  x = SpellBook[sp];
  foreach(string skill in spell->GetSkills() ) {
        if (x > (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5)) {
	        x = (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5);
	      }
  }
  return x;
}

varargs mixed CanCast(object spell) {
    string tmp;

    if (GetSleeping()) {
  	return "You are asleep!";
  	}
    if( GetParalyzed() ) {
	return "You cannot do anything.";
    }
    if( environment()->GetProperty("no magic") ) {
	return "Supernatural forces prevent your magic.";
  }
    if( !spell ) {
	return "No such spell exists in this reality.";
    }
  if (environment()->GetProperty("no conjuring")) {
      if(member_array("conjuring", spell->GetSkills()) != -1)
        return "Something prevents conjuring here.";
      }
  
  if (member_array("conjuring", spell->GetSkills()) != -1) {
      foreach(object w in GetUniqueWorn()) {
        if (member_array("metal", w->GetMaterials()) != -1 && w->GetArmourType() != A_WEAPON) {
        return "The metal in your " + w->GetKeyName() + " prevents "
                "your spell casting.";
       }
    }
  }
   if (member_array("natural magic", spell->GetSkills()) != -1) {
      foreach(object w in GetUniqueWorn()) {
        if (member_array("metal", w->GetMaterials()) != -1 && w->GetArmourType() != A_WEAPON) {
        return "The metal in your " + w->GetKeyName() + " prevents "
                "your spell casting.";
       }
    }
  }
   if (GetCombatStyle()) {
   	return "You cannot cast while using a combat style.";
   	}
    if( !GetSpellLevel(spell->GetSpell()) && userp() ) {
        return "You have never heard of that spell before.";
    }
    if( GetMagicPoints() < spell->GetMagicCost(this_object()) ) {
	return "You do not have the " + spell->GetMagicCost(this_object()) + " mana required.";
    }
    if( GetStaminaPoints() < spell->GetStaminaCost(this_object()) ) {
	return "You are too tired to expend " + spell->GetStaminaCost(this_object()) + " stamina.";
    }
    foreach(string skill in spell->GetSkills()) {
	if( GetSkillLevel(skill) < spell->GetRequiredSkill(skill) ) {
	    return "That magic is beyond your comprehension.";
	}
  }  
  return 1;
}

varargs mixed eventPrepareCast(string verb, mixed array args...) {
    object spell = SPELLS_D->GetSpell(verb = lower_case(verb));
    object array targets, send_to;
    string special, arg;
    mixed tmp;
    int type;
       string cast_pretext = "";

    tmp = spell->eventParse(this_object(), args...);
    if( !arrayp(tmp) ) {
	if( stringp(tmp) ) {
	    eventPrint(tmp);
	}
	else {
	    eventPrint("You are confused.");
	}
	return 1;
    }
    args = tmp;
    targets = spell->GetTargets(this_object(), args...);
    if (!sizeof(targets)) {
    	eventPrint(spell->GetErrorMessage());
    	return -1;
    }
    
    args = filter(args, (: stringp :));
    if( spell->GetAutoHeal() == 0 ) {
	if( !sizeof(args) ) {
	    object array existing = filter(targets, (: $1 :));
	    
	    if( sizeof(existing) != 1 ) {
		error("This spell was poorly constructed.");
	    }
	    arg = existing[0]->GetRandomLimb("torso");
	}
	else {
	    arg = args[0];
	}
    }
    else {
	if( !sizeof(args) ) {
	    arg = 0;
	}
	else {
	    arg = args[0];
	}
    }
    
        special = "%^BLUE%^BOLD%^uttering an incantation%^RESET%^";
    
    if( targets ) {
	send_to = filter(targets, (: environment($1) == environment() :));
    }
    else {
	send_to = 0;
    }
    
    // "Dzames closes his eyes and begins uttering an incantation.
    cast_pretext = "$agent_name ";
    
    // first try to give an elemental pretext
    if( member_array("fire magic", spell->GetEnhanceSkills()) != -1 ) {
      cast_pretext =
      "Flame %^BOLD%^RED%^dances%^RESET%^ from $agent_possessive_noun "
      "twirling fingertips as $agent_nominative ";
    } else if( member_array("ice magic", spell->GetEnhanceSkills()) != -1 ) {
      cast_pretext =
      "$agent_possessive_noun breath turns to a %^BOLD%^WHITE%^cold "
      "fog%^RESET%^ as $agent_possessive_noun ";
    } else if( member_array("shock magic", spell->GetEnhanceSkills()) != -1 ) {
      cast_pretext =
      "$agent_possessive_noun hair %^BOLD%^YELLOW%^sparks%^RESET%^ and stands "
      "on end as $agent_nominative ";
    } else if( member_array("poison magic", spell->GetEnhanceSkills()) != -1 ) {
      cast_pretext =
      "A %^BOLD%^GREEN%^thick ichor%^RESET%^ drips from "
      "$agent_possessive_noun pointing finger as $agent_nominative ";
      
    // okay we got no elements attempt a subschool pretext.
    } else if( member_array("enchantment", spell->GetSkills()) != -1) {
      cast_pretext =
      "The air seems to %^BOLD%^CYAN%^shimmer with potential%^RESET%^ as "
      "$agent_name ";
    } else if( member_array("necromancy", spell->GetSkills()) != -1) {
      cast_pretext = 
      "The smell of %^BOLD%^BLACK%^gravedust%^RESET%^ fills "
      "the air as $agent_name ";
    } else if( member_array("healing", spell->GetSkills()) != -1) {
      cast_pretext =
      "You are filled with a %^GREEN%^sense of calm%^RESET%^ as $agent_name ";
    } else if( member_array("evokation", spell->GetSkills()) != -1) {
      cast_pretext =
      "The ground %^YELLOW%^trembles ominously%^RESET%^ as $agent_name ";
    // this is what we call future proofing
    } else if( member_array("illusion", spell->GetSkills()) != -1) {
      cast_pretext =
      "%^BOLD%^BLACK%^Shadows%^RESET%^ and %^CYAN%^BOLD%^phantasms%^ twist "
      "and turn around about $agent_name as $agent_objective ";
    }
    
    if( member_array("conjuring", spell->GetSkills()) != -1 ) {
      send_messages(({ "whisper", "gesticulate" }),
        cast_pretext + "$agent_verb %^MAGENTA%^words of power%^RESET%^ "
        "and $agent_verb strangely.",
        this_object(), send_to, environment());
    } else if ( member_array("faith", spell->GetSkills()) != -1 ){
      send_messages(({ "shout"}),
        cast_pretext+ "$agent_verb %^BLUE%^pleas in an ancient " 
        "tongue%^RESET%^ to $agent_possessive god!",
        this_object(), send_to, environment());
    } else if ( member_array("natural magic", spell->GetSkills()) != -1 ){
      send_messages(({ "howl"}),
        cast_pretext + "$agent_verb %^BOLD%^GREEN%^primordial%^RESET%^ words "
        "of supplication to the skies!",
        this_object(), send_to, environment());
    } else if ( member_array("practical magic", spell->GetSkills()) != -1 ) {
      send_messages(({ "mutter"}),
        cast_pretext + "coarsely $agent_verb some weak "
        "%^CYAN%^words of power%^RESET%^ while frantically waving "
        "$agent_possessive hands.",
        this_object(), send_to, environment());

    // more like present proofing (turns out illusion is a major sphere? ish?
    } else if( member_array("illusion", spell->GetSkills()) != -1) {
      send_messages(({ "weave"}),
        cast_pretext + "$agent_verb a %^BOLD%^MAGENTA%^hypnotic pattern%^RESET%^ "
        "through the air!", 
        this_object(), send_to, environment());
    } else if( member_array("vampirism", spell->GetSkills()) != -1) {
      send_messages(({ "bare", "flush"}),
        cast_pretext + "$agent_verb $agent_possessive %^BOLD%^WHITE%^fangs%^RESET%^ "
		    "and%^RED%^ $agent_verb red with stolen blood!%^RESET%^",
		    this_object(), send_to, environment());
    } else {
      // "Dzames closes his eyes and begins uttering an incantation.
      send_messages(({ "close","begin"}),
        cast_pretext + "$agent_verb $agent_possessive eyes and $agent_verb "
        "%^BOLD%^BLUE%^uttering an incantation%^RESET%^",
        this_object(), send_to, environment());      
    }

    type = spell->GetSpellType();
    if( GetInCombat() || (type == SPELL_COMBAT) ) {
	    if( type == SPELL_COMBAT ) {
	    SetAttack(targets, (: eventCast($(spell), $(arg), $(targets)) :),
		      ROUND_MAGIC);
	}
	else {
	    SetAttack(0, (: eventCast($(spell), $(arg), $(targets)) :), ROUND_MAGIC);
	}
    }
    else {
	eventCast(spell, arg, targets);
    }
    return 1;
}

static varargs void eventCast(object spell, string limb, object array targs) {
  string name = spell->GetSpell();
  
  if( spell->CanCast(this_object(), SpellBook[name], limb, targs) ) {
	  if( SpellBook[name] < 100 ) {
	    eventTrainSpell(spell);
	  }
	  if (!spell->eventTestFailure(this_object(), SpellBook[name], limb, targs)) {
	    spell->eventCast(this_object(), SpellBook[name], limb, targs);
	  }
  }
}

mixed eventLearnSpell(string spell) {
    object magic = SPELLS_D->GetSpell(spell = lower_case(spell));

    foreach(string skill in magic->GetSkills()) {
	if( magic->GetRequiredSkill(skill) > GetSkillLevel(skill) ) {
	    return 0;
	}
    }
    if( !SpellBook[spell] ) {
	SpellBook[spell] = 1;
    }
    return 1;
}

mapping eventForgetSpell(string spell) {
	map_delete(SpellBook, spell);
	return SpellBook;
}


static void eventTrainSpell(object spell) {
    string name = spell->GetSpell();
    int x = SpellBook[name] + 1; 
    foreach(string skill in spell->GetSkills() ) {
        if ( (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5) < x) {
	      return;
	      }
    }
    SpellBook[name] = x;
    if (x < 100) AddExperience(20 * spell->GetSpellLevel());
}

int SetSpellBookLevel(string spell, int x) {
	SpellBook[spell] = x;
	return SpellBook[spell];
}

int SetSongBookLevel(string spell, int x) {
	SongBook[spell] = x;
	return SongBook[spell];
}

void heart_beat() {
	
	if (RecoveryTime) {
		if (!GetSleeping()) RecoveryTime--;
		  else RecoveryTime -= 50;
		if (RecoveryTime <= 0) {
			RecoveryTime = 0;
      if (sizeof(GetSpellBook()))
			  eventPrint("Your mind is no longer clouded.");
		}
	}
}

void create() {
	AddSave( ({ "RecoveryTime" }) );
}

mapping GetSongBook() {
    return copy(SongBook);
}

static void SetSongBook(mapping book) {
    SongBook = book;
}

int GetSongLevel(string sp) {
  int x;
  object spell = SONGS_D->GetSong(sp);
  x = SongBook[sp];
  foreach(string skill in spell->GetSkills() ) {
        if (x > (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5)) {
	        x = (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5);
	      }
  }
  return x;
}


int SetCannotSing(int x) {
  return (NoSing = x);
  }

int GetCannotSing() {
  return (NoSing);
  }


varargs mixed CanSing(object song) {
  if (GetSleeping()) return "You are asleep.";
    if (GetCombatStyle()) {
      return "You cannot use magic while using a combat style.";
    }
    if( GetParalyzed() ) {
	return "You cannot do anything.";
    }
    if( environment()->GetProperty("no magic") ) {
	return "Supernatural forces prevent your magic.";
    }
    if( !song ) {
	return "No such song exists in this reality.";
    }
    if( song->GetRequiredSkill("instrumental music") &&
       !present("bard_instrument", this_object()) ) {
      return "But you have no instrument!";
      }
    if( !SongBook[song->GetSong()] && userp() ) {
        return "You do not know how to sing that song.";
    }
    if( GetMagicPoints() < song->GetMagicCost(this_object()) ) {
	return "You do not have the " + song->GetMagicCost(this_object()) + " mana required.";
    }
    if( GetStaminaPoints() < song->GetStaminaCost(this_object()) ) {
	return "You do not have the " + song->GetStaminaCost(this_object()) + " stamina required.";
    }
    if ( GetHealthPoints() < song->GetHealthCost(this_object()) ) {
       return "Singing that song might kill you!";
       }
  if ( GetCannotSing() ) {
    return "You fail to summon the magical power required.";
   }
  foreach(string skill in song->GetSkills()) {
	  if( GetSkillLevel(skill) < song->GetRequiredSkill(skill) ) {
          return "That song is beyond your comprehension.";
	  }
	}
  if (sizeof(song->GetReligion()))
    if (member_array(GetReligion(), song->GetReligion()) == -1) {
      return "You are not of the proper faith.";
    }
  foreach(object w in GetUniqueWorn()) {
    if (member_array("metal", w->GetMaterials()) != -1 && w->GetArmourType() != A_WEAPON) {
      return "The metal in your " + w->GetKeyName() + " prevents your musical magic.";
       }
    }
    return 1;
}

varargs mixed eventPrepareSong(string verb, mixed array args...) {
    object song = SONGS_D->GetSong(verb = lower_case(verb));
    object array targets, send_to;
    object array newbies;
    string special, arg;
    mixed tmp;
    int type;

    tmp = song->eventParse(this_object(), args...);
    if( !arrayp(tmp) ) {
	if( stringp(tmp) ) {
	    eventPrint(tmp);
	}
	else {
	    eventPrint("You are confused.");
	}
	return 1;
    }
    args = tmp;      
    targets = song->GetTargets(this_object(), args...);
   if (!sizeof(targets)) {
     //mahkefel 2015: making it clear that area songs need things to area.
     if (song->GetAreaSong()) {
       eventPrint("But you have no audience!");
     } else {
       eventPrint("Sing it to whom?");
     }
     return 0;
   }
  if (song->GetSongType() == SONG_COMBAT) {
    newbies = filter(targets, (: newbiep :));
    if (userp(this_object()))
    targets = targets - newbies;
    if (!sizeof(targets)) {
      //mahkefel 2015: making it clear that area songs need things to area.
      if (song->GetAreaSong()) {
        eventPrint("But you have no audience!");
      } else {
        eventPrint("Sing it to whom?");
      }
      return 0;
      }
  }
  args = filter(args, (: stringp :));
  if ( (song->GetAutoHeal() == 0) || (song->GetAutoDamage() == 0) ) {
	if( !sizeof(args) ) {
	    object array existing = filter(targets, (: $1 :));
	    
            if(!sizeof(existing)) {
		error("This song was poorly constructed.");
	    }
     if (!(song->GetAffectsAllLimbs())) 
	    arg = existing[0]->GetRandomLimb("torso");
	}
	else {
	    arg = args[0];
	}
    }
    else {
	if( !sizeof(args) ) {
	    arg = 0;
	}
	else {
	    arg = args[0];
	}
    }
        special = "a song";
  if (!sizeof(targets)) {
	send_to = filter(targets, (: environment($1) == environment() :));
    }
    else {
	send_to = 0;
    }
  send_messages( ({ "clear", "begin" }),
      "$agent_name $agent_verb $agent_possessive throat and "
      "$agent_verb %^YELLOW%^singing%^RESET%^ with gusto!",
            this_object(),
		  send_to, environment());
    type = song->GetSongType();
    if( GetInCombat() || (type == SONG_COMBAT) ) {
	if( type == SONG_COMBAT ) {
	    SetAttack(targets, (: eventSing($(song), $(arg), $(targets)) :),
		      ROUND_MAGIC);
	}
	else {
	    SetAttack(0, (: eventSing($(song), $(arg), $(targets)) :),
		      ROUND_MAGIC);
	}
    }
    else {
	eventSing(song, arg, targets);
    }
    return 1;
}

static varargs void eventSing(object spell, string limb, object array targs) {
  string name = spell->GetSong();
  
  if( spell->CanSing(this_object(), SongBook[name], limb, targs) ) {
	  if( SongBook[name] < 100 ) {
	    eventTrainSong(spell);
	  }
	  if (!spell->eventTestFailure(this_object(), SongBook[name], limb, targs)) {
	    spell->eventSing(this_object(), SongBook[name], limb, targs);
	  }
  }
}

mixed eventForgetSong(string song) {
  if (SongBook[song]) {
     eventPrint("You forget the harmony and lyrics to " + song + ".");
    map_delete(SongBook, song);
    return 1;
  } 
  return 0;
  }

mixed eventLearnSong(string song) {
    object magic = SONGS_D->GetSong(song = lower_case(song));

    foreach(string skill in magic->GetSkills()) {
	if( magic->GetRequiredSkill(skill) > GetSkillLevel(skill) ) {
	    return 0;
	}
    }
  if (sizeof(magic->GetReligion()))
    if (member_array(GetReligion(), magic->GetReligion()) == -1) {
    return 0;
    }
    if( !SongBook[song] ) {
	SongBook[song] = 1;
    }
    return 1;
}

varargs void eventTrainSong(object song, int num) {
    string name = song->GetSong();
    int x = SongBook[name] + (num ? num : 1);
    
    foreach(string skill in song->GetSkills() ) {
   if( (5*(GetSkillLevel(skill) + 1 - song->GetRequiredSkill(skill))) < x) {
	    return;
	}
    }
    SongBook[name] = x;
    if (x < 100) AddExperience(20 * song->GetSongLevel());
}
