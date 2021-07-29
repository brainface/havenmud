/*    /lib/npc.c
 *    from the Nightmare IV LPC Library
 *    the standard non-player character object
 *    created by Descartes of Borg 950323
 *    Version: @(#) npc.c 1.10@(#)
 *    Last Modified: 99/7/7 by Zaxan@Haven
 */

#include <lib.h>
#include <daemons.h>
#include <position.h>
#include <armour_types.h>
#include <message_class.h>
#include <loot.h>
#include "include/npc.h"

inherit LIB_NPC_INTERACTIVE;
inherit LIB_LIVING;

private int ActionChance, CombatActionChance;
private int NoDrag = 0;
private int Test = 0;
private int RPC = 0;
private mixed Encounter;
private string *EnemyNames;
private static int Unique;
private int Limit;
private static mixed Die, Action, CombatAction;
private static mapping Inventory;
private static mapping CorpseItems;
private string Owner;
private int Petable;
private string *FirstCommands;
private int Loot;
mixed *SpecialLoot;
mixed Greet;

// command white/black listing
string* AllowedVerbs = ({ });
string* DeniedVerbs = ({ });

void eventFirstCommands();

static void create() {
    AddSave( ({ "CarriedMass" }) );
    SetSaveRecurse(1);
    npc_interactive::create();
    living::create();
    npc_interactive::Setup();
    SetPK(1);
    SetOpacity(0);
    EnemyNames = ({});
    Encounter = 0;
    CombatActionChance = 0;
    ActionChance = 0;
    Unique = 0;
    Limit = 0;
    Inventory = ([]);
    Owner = "";
    FirstCommands = ({ });
    Loot = LOOT_NONE;
    SpecialLoot = ({ });
    call_out( (: eventFirstCommands :), 0);
    Greet = "Your greeting seems to be ignored.";
}

string GetTown() {
	string bleh, domain, subdir;
	string NewTown;
	string *tmp;
 
 if (::GetTown() != "Wilderness") return ::GetTown();
 
 if(sscanf(file_name(this_object()), "/std/%s", bleh)) {
			::SetTown("Wilderness");
		  return ::GetTown();
		}
 if(sscanf(file_name(this_object()), "/realms/%s", bleh)) {
			::SetTown("Wilderness");
		  return ::GetTown();
		}

 if(!sscanf(file_name(this_object()), "/domains/%s/%s/%s/%s", domain, subdir, NewTown, bleh)) {
			::SetTown("Wilderness");
		  return ::GetTown();
		}
 if (subdir != "towns") {
  ::SetTown("Wilderness");
  return ::GetTown();
  }
 tmp = explode(NewTown, "_");
 foreach(string word in tmp) { 
 	tmp -= ({ word }); 
 	tmp += ({ capitalize(word) });
 	}
 NewTown = implode(tmp, " ");
 ::SetTown(NewTown);
 return ::GetTown();
}

mixed direct_command_liv_to_str() {
/*  if (this_player()->GetTown() == GetTown()) {
    if (this_player()->GetSocialRank() == 6) {
      if (this_player()->GetLevel() > GetLevel()) return 1;
    }
  } */
  if (GetOwner() == this_player()->GetKeyName() )
    return 1;
    return capitalize(GetKeyName() ) + " will not listen to you.";
}

static void init() {
    string *enemies;
    
  if( !query_heart_beat() ) {
        eventCheckHealing();
        set_heart_beat( GetHeartRate() );
    }
  if( sizeof(enemies = GetEnemyNames()) ) {
	  if( member_array((string)this_player()->GetKeyName(),enemies) != -1 ) {
	    eventExecuteAttack(this_player());
	    return;
	    }
  }
  if( Encounter ) {
    int x = 0;

    if( functionp(Encounter) ) {
      x = (int)evaluate(Encounter, this_player());
    }
    else if( arrayp(Encounter) ) {
      if( member_array(this_player()->GetKeyName(), Encounter) > -1 ) {
        x = 1;
      }
      else {
        x = 0;
      }
    }
    else if( (int)this_player()->GetStatLevel("charisma") < Encounter ) {
      if (base_name(this_player()) != base_name(this_object()) ) x = 1;
    }
    if(x==1) {
      SetAttack(this_player());
    }
  }
}

static void heart_beat() {
    int position;
    
    living::heart_beat();
     if (!environment()) {
      eventDestruct();
      return;
      }
    if( !ContinueHeart() ) {
        set_heart_beat(0);
        return;
    }
    // mahk: I don't think heartrate changes ever applied
    set_heart_beat(GetHeartRate());
    position = GetPosition();
    AddFood(1); AddDrink(1);
    if( position == POSITION_LYING || position == POSITION_SITTING ) {
       if (!userp(this_object()) && GetInCombat())
	       eventForce("stand up");
    }
    if(!userp(this_object()))
    if( !GetInCombat() && ActionChance > random(100) ) {
        int x;
        if (GetSleeping() || GetParalyzed()) return;
        if( functionp(Action) ) evaluate(Action);
        else if( pointerp(Action) && (x = sizeof(Action)) ) {
            string act;

            act = Action[random(x)];
            if( act && act != "" && act[0] == '!' && act != "!" ) {
                act = act[1..];
                eventForce(act);
            }
            else message("other_action", act, environment());
        }
    }
    else if( GetInCombat() && CombatActionChance > random(100) ) {
        int x;
        if (GetSleeping() || GetParalyzed()) return;
        if (!GetCurrentEnemy()) return;
        if( functionp(CombatAction) ) evaluate(CombatAction);
        else if( pointerp(CombatAction) && (x = sizeof(CombatAction)) ) {
            string act;

            act = CombatAction[random(x)];
            if( act && act != "" && act[0] == '!' && act != "!" ) {
                act = act[1..];
                eventForce(act);
            }
            else message("other_action", act, environment());
        }
    }
}

void receive_message(string cl, string msg) { catch_tell(msg); }

void catch_tell(string msg) {
    eventPrint(msg);
  }

static int Destruct() {
    living::Destruct();
    return npc_interactive::Destruct();
}

void eventReconnect() { }

/* ***************  /lib/npc.c command functions  ************** */
static int cmdAll(string arg) {
    object env;
    string verb;

    verb = query_verb();
    env = environment();
    if( npc_interactive::chat_command(verb + " " + arg) == "" ) return 1;
    return npc_interactive::cmdAll(arg);
}

/* ***************  /lib/npc.c events  *************** */

void eventFirstCommands() {
  if (!environment()) return;
  if (!sizeof(FirstCommands)) return;
  foreach(string c in FirstCommands) {
    eventForce(c);
  }
}

int eventCompleteMove(mixed dest) {
    mixed val;
    string file;
    int x;

    if( environment() ) return living::eventMove(dest);
    else x = living::eventMove(dest);
    if( !x ) return x;
    foreach(file, val in Inventory) {
        object ob;

        if (!val) continue;
        if( intp(val) ) {
            if( val <= 0) {
                ob = unique(file, -val);
                if( ob ) ob->eventMove(this_object());
            }
            else while(val--)
              if( ob = new(file) ) ob->eventMove(this_object());
        }
        else if( stringp(val) )  {
            if( !(ob = new(file)) ) continue;
            if( ob->eventMove(this_object()) ) eventForce(val);
        }
        else if( functionp(val) ) {
            if( !(ob = new(file)) ) continue;
            if( ob->eventMove(this_object()) ) evaluate(val);
        }
    }
    return x;
}

int eventDestruct() {
    npc_interactive::eventDestruct();
}

mixed SetGreet(mixed x) {
  return Greet = x;
}

void eventGreet(object who) {
  if (!Greet) who->eventPrint(GetCapName() + " seems to ignore your greeting.");
  if (stringp(Greet)) who->eventPrint(Greet);
  if (functionp(Greet)) { evaluate(Greet, who); }
}


varargs int eventDie(object agent) {
    int x;
    int val;
    string file;

    if (userp(this_object())) eventForce("restore");
    if( CorpseItems )
      foreach(file, val in CorpseItems)
      {
          object ob;
          if( val <= 0) {
              ob = unique(file, -val);
              if( ob ) ob->eventMove(this_object());
          }
          else while(val--)
            if( ob = new(file) ) ob->eventMove(this_object());
      }
		LOOT_D->eventDie(this_object());
    if( (x = living::eventDie(agent)) != 1 ) return x;
    if( stringp(Die) )  {
        message("other_action", Die, environment(), ({ this_object() }));
        if( agent) message("my_action", "You kill " + GetName() + ".", agent);
    }
    else if( functionp(Die) && !evaluate(Die, agent) ) return 0;
    else {
        message("other_action", "%^BOLD%^%^RED%^"+ GetName() + " dies.",
                environment(), ({ this_object() }) );
        if( agent ) message("my_action", "You kill " + GetName() + ".", agent);
    }
   eventPrint("You die.");
   eventForce("restore");
   set_heart_beat(0);
   eventDestruct();
   return 1;
}

void eventEnemyDied(object ob) {
    living::eventEnemyDied(ob);
    EnemyNames -= ({ (string)ob->GetKeyName() });
}

int eventMove(mixed dest) {
    int ret;

    ret = eventCompleteMove(dest);
    eventMoveFollowers(environment(this_object()));
    return ret;
}

varargs int eventMoveLiving(mixed dest, string omsg, string imsg) {
    object *inv;
    object prev;
    string msgclass;

    if( prev = environment() ) {
        if( stringp(dest) ) {
            if(dest[0] != '/') {
                string *arr;

                arr = explode(file_name(prev), "/");
                dest = "/"+implode(arr[0..sizeof(arr)-2], "/")+"/"+dest;
            }
        }
        if( !eventCompleteMove(dest) ) {
	    eventPrint("You remain where you are.");
            return 0;
        }
        inv = filter(all_inventory(prev), (: (!GetInvis($1) && living($1) &&
                                              ($1 != this_object())) :));
        if( !omsg || omsg == "" ) omsg = GetMessage("telout");
        else omsg = GetMessage("leave", omsg);
	inv->eventPrint(omsg, MSG_ENV);
        eventDescribeEnvironment(GetBriefMode());
    }
    else if( !eventCompleteMove(dest) ) {
	eventPrint("You remain where you are.");
        return 0;
    }
    inv = filter(all_inventory(environment()),
                 (: (!GetInvis($1) && living($1) && ($1 != this_object())) :));
    if( (!imsg || imsg == "") && (!omsg || omsg == "") )
      imsg = GetMessage(msgclass = "telin");
    else if( !imsg || imsg == "" ) imsg = GetMessage(msgclass = "come", imsg);
    else imsg = replace_string(imsg, "$N", GetName());
    inv->eventPrint(imsg, MSG_ENV);
    eventMoveFollowers(environment(this_player()));
    return 1;
}

varargs int eventPrint(string msg, mixed arg2, mixed arg3) {
  int msg_class;
  mapping TermInfo = TERMINAL_D->query_term_info("ansi");
  if (!msg) return 0;
  if (!arg2 && !arg3) msg_class = MSG_ENV;
  else if(!arg2) {
     if (!intp(arg3)) msg_class = MSG_ENV;
      else msg_class = arg3;
      }
    else if(!intp(arg2)) msg_class = MSG_ENV;
  else msg_class = arg2;
  msg = terminal_colour(msg + "%^RESET%^", TermInfo);
  msg = msg + "\n";
  receive(msg);
  return 1;
}

int eventReceiveObject() {
    object ob;

    ob = previous_object();
    if( !ob || !npc_interactive::eventReceiveObject() ) return 0;
    AddCarriedMass((int)ob->GetMass());
    return 1;
}

int eventReleaseObject() {
    object ob;

    ob = previous_object();
    if( !ob || !npc_interactive::eventReleaseObject() ) return 0;
    AddCarriedMass( -((int)ob->GetMass()) );
    return 1;
}

varargs int eventShow(object who, string str) {
    if( !living::eventShow(who, str) ) return 0;
    eventPrint((string)this_player()->GetName() + " looks you over.");
    return 1;
}

/*  ***************  /lib/npc.c modal functions  *************** */

int CanCarry(int amount) { return living::CanCarry(amount); }

mixed CanGet(object who) { return GetName() + " is a living being!"; }

int CanReceive(object ob) { return CanCarry((int)ob->GetMass()); }

/*  ***************  /lib/npc.c lfuns  ***************  */

static int ContinueHeart() {
    object env;

    if (!this_object()) return 0;
    if( !(env = environment()) ) { eventDestruct(); return 0; }
    return 1;
}

/*  ***************  /lib/npc.c data functions  ***************  */

mapping SetInventory(mapping mp ) { return (Inventory = mp); }

mapping GetInventory() { return Inventory; }

mixed AddInventory(string prop, mixed val) { return (Inventory[prop] = val); }

varargs string SetRace(string race, mixed extra) {
    race = living::SetRace(race, extra);
    eventCompleteHeal(GetMaxHealthPoints());
    if (GetTown() != "Wilderness") MORALITY_D->SetNPCMorality(this_object());
    return race;
}

string SetTown(string str) {
  string s = ::SetTown(str);
  MORALITY_D->SetNPCMorality(this_object());
  return str;
}

string GetClass() {
  if (!::GetClass()) { return "animal"; }
  return ::GetClass();
}

string SetClass(string cls) {
    string *skills;
    int x, i;

    cls = living::SetClass(cls);
    x = GetLevel();
    i = sizeof(skills = GetSkills());
    while(i--) {
        int y;

        y = (GetSkillClass(skills[i]) || 5);
        // that +4 is not working for newbs --mahk
        SetSkill(skills[i], (2*x) /*+ 4*/, y); 
    }
    eventCompleteHeal(GetMaxMagicPoints());
    return cls;
}

int SetLevel(int x) {
    string *tmp;
    int i;

    living::SetLevel(x);
    if (!x) debug("SetLevel(0)");
    i = sizeof(tmp = GetSkills());
    if (!i) debug("SetLevel before SetClass");
    while(i--) {
        int y;

        y = (GetSkillClass(tmp[i]) || 5);
        // that +4 is not working for newbs --mahk
        SetSkill(tmp[i], (2 * x) /*+ 4*/, y);
    }
    i = sizeof(tmp = GetStats());
    while(i--) {
        int y;

        y = (GetStatClass(tmp[i]) || 5);
       //SetStat(tmp[i], (3*x)/y + GetStatLevel(tmp[i]), y);
       // mahkefel: cahnged this to below, multiple setlevels gave npcs hilarious stats.
      SetStat(tmp[i], (3*x)/y + 25, y);
    }
    eventCompleteHeal(GetMaxHealthPoints());
    return GetLevel();
}

int GetSkillLevel(string skill) {
	string a, b;
	int x;
	x = living::GetSkillLevel(skill);
  if (strsrch(skill, "combat") != -1)
	  if (!x)	return (3 * GetLevel() /2);
  return x;
}

int SetHealthPoints(int x) {
    if( x > GetMaxHealthPoints() )
      SetStat("durability", (x-50)/10, GetStatClass("durability"));
    AddHealthPoints( x - GetHealthPoints() );
    return GetHealthPoints();
}

int SetMaxHealthPoints(int x) {
    SetStat("durability", to_int((x-50)/10), GetStatClass("durability"));
    return GetMaxHealthPoints();
}

int SetMagicPoints(int x) {
    if( x > GetMaxMagicPoints() )
      SetStat("intelligence", (x-50)/10, GetStatClass("intelligence"));
    AddMagicPoints( x - GetMagicPoints() );
    return GetMagicPoints();
}

int SetMaxMagicPoints(int x) {
    SetStat("intelligence", (x-50)/10, GetStatClass("intelligence"));
    return GetMaxMagicPoints();
}

float SetStaminaPoints(float x) {
    if( x > GetMaxStaminaPoints() )
      SetStat("agility", to_int((x-50.0)/10.0), GetStatClass("agility"));
    AddStaminaPoints( x - GetStaminaPoints() );
    return to_float(GetStaminaPoints());
}

float SetMaxStaminaPoints(float x) {
    SetStat("agility", (x-50.0)/10.0, GetStatClass("agility"));
    return GetMaxStaminaPoints();
}

varargs void SetCurrency(mixed val, int amount) {
  int amt;
    if( stringp(val) ) {
      amount *= currency_rate(val);
      AddCurrency(val, amount - GetCurrency(val));
      return;
    }
    if( mapp(val) ) {
        foreach(string currency in keys(val)) {
          AddCurrency(currency, (val[currency] * currency_rate(currency)) - GetCurrency(currency));
        }
    return;
    }
    error("Bad argument 1 to SetCurrency().");
}

int AddCurrency(string val, int amt) {
  int lev = GetLevel() * 10 * currency_rate(val);
  if (amt > lev) amt = lev;
  if (!GetLevel()) debug("SetCurrency(" + val + ") before SetLevel in:");
  return ::AddCurrency(val, amt);
}

mixed SetEncounter(mixed val) { return (Encounter = val); }

string *AddEncounter(string nom) {
    if( !stringp(nom) ) error("Bad argument 1 to AddEncounter()\n");
    if( Encounter && !pointerp(Encounter) ) return 0;
    else Encounter += ({ convert_name(nom) });
    return Encounter;
}

string *RemoveEncounter(string nom) {
    if( !stringp(nom) ) error("Bad argument 1 to RemoveEncounter()\n");
    if( Encounter && !pointerp(Encounter) ) return 0;
    else Encounter -= ({ convert_name(nom) });
    return Encounter;
}

mixed GetEncounter() { return Encounter; }

mixed SetDie(mixed val) { return (Die = val); }

mixed GetDie() { return Die; }

string SetKeyName(string nom) {
    set_living_name(nom = npc_interactive::SetKeyName(nom));
    return nom;
}

string GetName() { return npc_interactive::GetName(); }

string GetCapName() { return npc_interactive::GetCapName(); }

string GetShort() { return npc_interactive::GetShort(); }

string GetFullShort() { return GetShort(); }

varargs string GetLong(string str) {
    mapping counts;
    string item, what;
    object *inv= all_inventory();

    str = npc_interactive::GetLong() + "\n";
    inv = filter(inv, (: !$1->GetInvis() :) );
    what = "The "+GetGender()+" "+GetRace();
    str += living::GetLong(what);
    foreach(item in map(inv,
                        (: (string)$1->GetAffectLong(this_object()) :)))
      if( item ) str += item + "\n";
    counts = ([]);
    foreach(item in map(inv,(: (string)$1->GetEquippedShort() :)))
      if( item ) counts[item]++;
    if( sizeof(counts) ) str += GetCapName() + " is carrying:\n";
    foreach(item in keys(counts))
      str += capitalize(consolidate(counts[item], item)) + "\n";
    return str;
}

string GetRawLong() {
   return npc_interactive::GetLong();
}

void SetAction(int chance, mixed val) {
    ActionChance = chance;
    if( stringp(val) ) val = ({ val });
    else if( !functionp(val) && !pointerp(val) )
      error("Bad argument 2 to SetAction()\n");
    Action = val;
}

mixed GetAction() { return Action; }

int GetActionChance() { return ActionChance; }

void SetCombatAction(int chance, mixed val) {
    CombatActionChance = chance;
    if( stringp(val) ) val = ({ val });
    else if( !functionp(val) && !pointerp(val) )
      error("Bad argument 2 to SetCombatAction()\n");
    CombatAction = val;
}

mixed GetCombatAction() { return CombatAction; }

int GetCombatActionChance() { return CombatActionChance; }

int AddCarriedMass(int x) { return living::AddCarriedMass(x); }

string *SetFirstCommands(string *s) {
  if (!arrayp(s)) s = ({ s });
  return FirstCommands = s;
}

string *GetFirstCommands() { return FirstCommands; }

mixed *GetCommands() { return commands(); }

int SetUnique(int x) {
    Unique = x;
    if( Unique ) UNIQUE_D->eventTouchObject();
    return Unique;
}

int GetWarmth() { return 50; }

int GetUnique() { return Unique; }

int SetLimit(int x) { return (Limit = x); }

int GetLimit() { return Limit; }

int AddEnemy(object ob) {
    string tmp;
    
    if( !living::AddEnemy(ob) ) return 0;
    if( member_array(tmp = (string)ob->GetKeyName(), EnemyNames) == -1 )
      EnemyNames += ({ tmp });
    return 1;
}

string *GetEnemyNames() { return EnemyNames; }

int GetRadiantLight(int ambient) {
    return npc_interactive::GetRadiantLight(ambient);
}

int *GetScreen() { return ({ 80, 24 }); }

int eventDisplayStatus() {
  string hp, mp, sp;
  hp = GetHealthPoints() + "/" + GetMaxHealthPoints();
  mp = GetMagicPoints() + "/" + GetMaxMagicPoints();
  sp = GetStaminaPoints() + "/" + GetMaxStaminaPoints();

  eventPrint(hp + " " + mp + " " + sp);
  return 1;
  }

int SetTestChar(int x) {
  return (Test = x);
  }

int GetTestChar() {
  return (Test);
  }

int SetRPC(int x) {
   return (RPC = x);
}

int GetRPC() {
   return RPC;
}

void eventPage(string *lines) {
  foreach(string line in lines) {
     eventPrint(line);
    }
  }

mapping SetCorpseItems(mapping args)
{
  return CorpseItems = args;
}

mapping GetCorpseItems() { return CorpseItems; }

string GetOOCName() { return GetName(); }

string GetOwner() {
  return lower_case(Owner);
}

string SetOwner(string str) {
    if (this_object()->GetNoPet() != 1)
    return Owner = str;
    return "You cannot control that creature.";
}

int GetNoPet() {
    return Petable;
  }

int SetNoPet(int can) {
    return Petable = can;
}

int SetNoDrag(int num) { return NoDrag = num; }

int GetNoDrag() { return NoDrag; }
int GetHiding() { return 0; }
int SetHiding(int x) { }

string *GetTitles() { return ({ }); }
int GetDevelopmentPoints() { return 0; }
int AddDevelopmentPoints(int x) { return 0; }

int SetLoot(int x) { return Loot = x; }
int GetLoot()      { return Loot; }
int CheckLoot(int x) { return Loot & x; }

varargs mixed *SetSpecialLoot(string filename, int chance, mixed funcheck) {
  SpecialLoot = ({ filename, chance, funcheck });
  return SpecialLoot;
}

mixed *GetSpecialLoot() {
  return SpecialLoot;
}

int GetSpellLevel(string sp) {
  int x;
  mapping sb = GetSpellBook();
  object spell = SPELLS_D->GetSpell(sp);
  x = 100;
  foreach(string skill in spell->GetSkills() ) {
        if (x > (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5)) {
	        x = (5 * (GetSkillLevel(skill) - spell->GetRequiredSkill(skill)) + 5);
	      }
  }
  return x;
}

// mahk 2017: command overhaul
// if any allowed verbs are found, creature can ONLY be commanded
// to use those verbs.
string* SetAllowedVerbs(string* verbs) { return AllowedVerbs = verbs;}
string* GetAllowedVerbs() { return AllowedVerbs;}

// if any denied verbs are found, creature will refuse commands 
// starting with those verbs. If allowed verbs are also set, creature can
// only do allowed verbs unless they are also denied, but that's dumb, only
// use one function.
string* SetDeniedVerbs(string* verbs) { return DeniedVerbs = verbs;}
string* GetDeniedVerbs() { return DeniedVerbs;}  

// called by the command verb.
mixed eventCommand(object who, string command) {
  string verb = "";
  
  if (command == "") return 0;
  verb = explode(command," ")[0];
  
  // check for verb on the denied verbs list
  if (member_array(verb, DeniedVerbs) != -1) {
    if(who) who->eventPrint(capitalize(this_object()->GetShort()) 
      + " refuses to " + verb + ".");
    return 0;
  }
  
  // check for verb not on the allowed verb list, if it exists
  if (sizeof(AllowedVerbs) && member_array(verb, AllowedVerbs) == -1) {
    if(who) who->eventPrint(capitalize(this_object()->GetShort()) + 
    " will only follow these commands: " + implode(AllowedVerbs,", ") + ".");
    return 0;
  }
  
  // everything's good, do what you're told
  return this_object()->eventForce(command);  
}
