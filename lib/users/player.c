/*    /lib/player.c
 *    from the Nightmare IV LPC Library
 *    the player object
 *    created by Descartes of Borg 950321
 *    Version: @(#) player.c 1.13@(#)
 *    Last Modified: 96/11/02
 *   
 *    Modfied by Gabriel@Haven 10/15/99 to
 *      stat losses to revive instead of death
 *    Modified to add CanCast interger to assist
 *      in testing for metal armour 10/23/99
 *
 */

#include <lib.h>
#include <daemons.h>
#include <rooms.h>
#include <damage_types.h>
#include <message_class.h>
#include <position.h>
#include <daemons.h>
#include <config.h>
#include <clock.h>
#include <vision.h>
#include <std.h>
#include "include/player.h"

inherit LIB_INTERACTIVE;
inherit LIB_LIVING;

private string *Titles;
private string Story;
string Surname;
private int ApprovedStory;
private string OOCName;
private class quest *Quests;
private class death *Deaths;
private int DevelopmentPoints = 0, TitleLength, TitleAnd, NoRank;
private int TellRestricted = 0;
private int Retired = 0;
private int TestChar;
private int RPC;
private int CanCast;
private int IsBlind;
private int CanLocate;
private int SeveredHeads;
private int LastLevel, HighestLevel;
private string *LongDaemonData;
private mapping PermanentProperties = ([]);
private string *ExploredWorlds = ({});
private string *ImprovedStats = ({ });
private string *PartyMembers = ({ });

int SetTestChar(int x) { ApprovedStory = x; return TestChar = x; }
int GetTestChar() { return (TestChar); }
int SetRPC(int x) { return (RPC = x); }
int GetRPC() { return (RPC); }
int SetCanCast(int x) { return (CanCast = x); }
int GetCanCast() { return (CanCast); }

int SetRetired(int x) { return (Retired = x); }
int GetRetired() { return (Retired); }

int SetCanLocate(int x) { return CanLocate = x; }
int GetCanLocate() { return CanLocate; }

string GetOwner() { return 0; }




/* *****************  /lib/player.c driver applies  ***************** */

static void create() {
    AddSave( ({ "CarriedMass" }) );
    AddSave( ({ "TestChar", "RPC" }) );
    AddSave( ({ "PermanentProperties" }) );
    AddSave( ({ "StatsBonus" }) );
    AddSave( ({ "LastLevel", "HighestLevel" }) );
    AddSave( ({ "CanLocate", "ImprovedStats" }) );
    AddSave( ({ "Surname" }) );
    AddSave( ({ "SeveredHeads" }) );
    interactive::create();
    living::create();
    Story = 0;
    ApprovedStory = 0;
    CanLocate = 1;
    Titles = ({});
    TitleLength = 1;
    TitleAnd = 1;
    NoRank = 1;
    Surname = 0;
    Quests = ({});
    LastLevel = time();
}

static void heart_beat() {

    if(!interactive(this_object())) {
        set_heart_beat(0);
        return;
    }
    interactive::heart_beat();
    if( query_idle(this_object()) >= 3600 ) {
      CHAT_D->eventSendChannel("", "notify", capitalize(GetKeyName()) + " has idled out.", 1);
        if (GetInCombat()) eventWimpy();
        cmdQuit("master");
        return;
    }
    if (GetProperty("mission")) {
      MISSION_D->CheckMission(this_object(), GetProperty("mission"));
    }

    living::heart_beat();
}

static void net_dead()
{
  interactive::net_dead();
  set_heart_beat(0);
}

static int Destruct() {
  CHARACTER_D->eventSaveTime();
  living::Destruct();
  return interactive::Destruct();
}

mixed eventAsk(object who, string what) {
    if( what != "convert me" ) return 0;
    if( !GetReligion(1) ) return 0;
    who->SetProperty("converting", GetReligion(1));
    return 1;
}

void eventKillEnemy(object ob) {
    if (!ob) return;
    eventMoralAct(-(ob->GetMorality()));
    STATISTICS_D->eventKill(ob);
}

void eventDestroyEnemy(object died) {
  if (!died) return;
  eventMoralAct(-(died->GetMorality()*2));
  STATISTICS_D->eventKill(died);
}


void eventReconnect() {
    interactive::eventReconnect();
    living::eventReconnect();
    set_heart_beat(GetHeartRate());
}

/************** player.c command functions *************/
varargs int eventShow(object who, string str) {
    if( !living::eventShow(who, str) ) return 0;
    if( this_player() != this_object() )
    if(!this_player()->GetInvis() && !this_player()->GetProperty("assumed"))
    eventPrint((string)this_player()->GetName() + " looks you over.");
    return 1;
}

/* *****************  /lib/player.c events  *************** */

int eventDisplayStatus() {
    string str;
    int hp, mp, sp, max_hp, max_mp, max_sp;

    hp = GetHealthPoints();
    max_hp = GetMaxHealthPoints();
    mp = GetMagicPoints();
    max_mp = GetMaxMagicPoints();
    sp = GetStaminaPoints();
    max_sp = GetMaxStaminaPoints();
    if( percent(hp, max_hp) < 20.0 )
      str = "%^YELLOW%^hp: %^RED%^" + hp + "%^RESET%^/" + max_hp;
    else str = "%^YELLOW%^hp: %^RESET%^" + hp + "/" + max_hp;
    if( percent(mp, max_mp) < 20.0 )
      str += "   %^BLUE%^mp: %^RED%^" + mp + "%^RESET%^/" + max_mp;
    else str += "   %^BLUE%^mp: %^RESET%^" + mp + "/" + max_mp;
    if( percent(sp, max_sp) < 20.0 )
      str += "   %^GREEN%^sp: %^RED%^" + sp + "%^RESET%^/" + max_sp;
    else str += "   %^GREEN%^sp: %^RESET%^" + sp + "/" + max_sp;
    // str += "\n";
    if (GetSleeping()) str += " (sleeping: " + GetSleeping() + ")";
    if (GetParalyzed()) str += " (paralyzed: " + GetParalyzed() + ")";
    if (GetBlessed()) str += " (blessed: " + GetBlessed() + ")";
    if (GetCursed()) str += " (cursed: " + GetCursed() + ")";
    if (GetUndead()) str += " (%^RED%^undead%^RESET%^)";
    if (GetRecoveryTime()) str += " %^MAGENTA%^(dazed: " + GetRecoveryTime() + ")%^RESET%^";
    if (GetPoison()) str += " %^BOLD%^RED%^(poisoned: " + GetPoison() + ")%^RESET%^";
    if (GetBleeding()) str += " %^RED%^(bleeding: " + GetBleeding() + ")%^RESET%^";
    if (GetPosition() == POSITION_LYING) str += " (lying down)";
    if (GetPosition() == POSITION_SITTING) str += " (sitting)";
    if (GetCombatStyle()) str += " (" + GetCombatStyle() + ")";
    // mahkefel 2011: make combat action boosts display in status.
    if (GetCombatActionDescriptions()) str += GetCombatActionDescriptions();

    if (GetProperty("status") == "full") {
      str += "\n";
      str += "Food (" + GetFood() + ")";
      str += " Drink (" + GetDrink() + ")";
      if (GetAlcohol()) str += " Alcohol (" + GetAlcohol() + ")";
      if (GetSmoke()) str += " Smoke (" + GetSmoke() + ")";
      if (GetCaffeine()) str += " Caffeine (" + GetCaffeine() + ")";
      str += "\nXP: " + GetExperience() + "";
      str += " Morality: " + GetMorality() + "";
    }
    message("system", str, this_object());
    if (sizeof(GetMissingLimbs())) message("system", "Missing: " + conjunction(GetMissingLimbs(), "and"), this_object());
    eventDisplayConditions(this_object(), this_object());
    return 1;
}

static void eventDestroyUndead(object agent) {

  CHAT_D->eventSendChannel("Death", "players",
     capitalize(GetKeyName()) + " was destroyed by " +
     capitalize(agent->GetKeyName()) + ".");
    if(!GetTestChar())
    log_file("players/deaths", GetCapName() + " (" + GetLevel() + ") was destroyed at the hands of " 
                               + (agent ? (string)agent->GetCapName() : "an unknown source") +
                                 (agent ? " (" + agent->GetLevel() + ") " : " (N) " ) +
                               " (" + ctime(time()) + ")\n" +
                               " (" + short_file(base_name(agent)) + ") (" + 
                                 short_file(base_name(environment(this_object()))) + ")\n");
  eventPrint("As your Undead form is rended apart, you feel that "
             "familiar feeling of life passing from your body. Your "
             "soul rushes toward the Heavens, but this time nothing stops "
             "your ascent. You cease to exist in mortal form upon "
             "Kailie, and can only hope for rebirth in another form.");
    if( agent ) {
        
        environment()->eventPrint(agent->GetName() + " dispells from existence the undead creature " + GetName() + ".", ({agent,this_object() }));
        agent->eventPrint("You destroy the undead " + GetName() + ", losing a bit of your soul in the process.");
        agent->AddDevelopmentPoints(-1);
    } else {
        environment()->eventPrint(GetName() + " is removed from existence before your eyes.", this_object());
    }
  CHAT_D->eventSendChannel("", "ooc", "%^RED%^" + GetName() + " vanishes into the legends of history.%^RESET%^", 1);
  PLAYERS_D->RemovePlayer();
  BANISH_D->banish_name(GetKeyName());
  all_inventory()->eventDestruct();
  call_out((: Destruct :), 0);
}

int eventDie(object agent) {
    int x;
/*  if (userp(agent)) {
    environment()->eventPrint("%^RED%^" + GetCapName() + " dies.%^RESET%^", this_object());
    eventPrint("%^RED%^You die.%^RESET%^");
    CHAT_D->eventSendChannel("A cold wind", "ooc", "%^RED%^Death (from " + 
                             capitalize((agent->GetKeyName() || agent->GetShort())) + ") has claimed " + 
                             capitalize(GetKeyName()) + ".%^RESET%^");
    eventMove(ROOM_DEATH);
    SetParalyzed(20);
    return 1;
  } */
  if (!agent) (agent = this_object());
  CHAT_D->eventSendChannel("XP Loss", "reports", capitalize(GetKeyName()) + " lost " + GetExperience() + " XP");
    if (GetExperience() / 1000000) CHAT_D->eventSendChannel("A cold wind", "ooc", capitalize(GetKeyName()) + " lost more than " + (GetExperience() / 1000000) + " million experience!");
  AddExperience(-GetExperience());
  SetAttack(0);
  if (userp(agent) && agent != this_object() && GetUndead()) {
    eventPrint("Your soul refuses to be purged from the universe. "
               "Your body, however, is less than forgiving.");
    eventRevive();
    }
  if( (x = living::eventDie(agent)) != 1 ) return x;
  if(!GetTestChar())
    CHAT_D->eventSendChannel("A cold wind", "ooc", "%^RED%^Death (from " +
     capitalize((agent->GetKeyName() || agent->GetShort()))
     + ") has claimed " + capitalize(GetKeyName()) + ".%^RESET%^");
    CHAT_D->eventSendChannel("A cold wind", "fs", "%^RED%^Death (from " +
     capitalize((agent->GetKeyName() || agent->GetShort()))
     + ") has claimed " + capitalize(GetKeyName()) + ".%^RESET%^");
  if( !GetUndead() ) {
       eventDestroyUndead(agent);
       } else {
    class death this_death;
        
    CHAT_D->eventSendChannel("Death", "players",
     capitalize(GetKeyName()) + " was killed by " +
     capitalize((agent->GetKeyName() || agent->GetShort())) + ".");
    if(!GetTestChar())
      log_file("players/deaths", GetCapName() + " (" + GetLevel() +
             ") was killed by " +
             (agent ? capitalize(agent->GetKeyName()) : "an unknown source") +
             (agent ? " (" + agent->GetLevel() + ") " : " (N) " ) +

             " (" + ctime(time()) + ")\n" +
             " (" + short_file(base_name(agent)) + ") (" + 
             short_file(base_name(environment())) + ")\n");     
        this_death = new(class death);
        this_death->Date = time();
        if( agent)
          this_death->Enemy = ((string)agent->GetKeyName() || (string)agent->GetShort());
        if( !Deaths ) Deaths = ({ this_death });
        else Deaths += ({ this_death });
    message("system", 
      "You die.   \n"
      "You have a strange sensation as your soul passes from your body. "
      "You awaken different than you were.  You are undead.",
            this_object() );
        if( agent ) {
             
            message("other_action", GetName() + " drops dead by the hand "
                    "of " + (string)agent->GetName() + ".",
                    environment(this_object()), ({ agent, this_object() }));
           message("other_action", "You slaughter " + GetName() + ".",
                     agent);
        }
        else message("other_action", GetName() + " drops dead.",
                     environment(), ({ this_object() }) );
        NewBody(GetRace());
        
        SetParalyzed(0);
        SetSleeping(0);
        SetPoison(0);
        eventCompleteHeal(10000);
        AddFood(500);
        AddDrink(500);
        eventMove(ROOM_DEATH);
       }
    return 1;
}

void eventRevive() {
  string skill;
  int x = 0;
  if( !GetUndead() ) return;
  SetUndead(0);
  if( !newbiep()  )   { 
    foreach(skill in GetSkills()) {
      AddSkillLevels(skill, -(random(2)) );
    }
  }
  NewBody(GetRace());
  eventCompleteHeal(GetMaxHealthPoints());
  AddMagicPoints(-(GetMaxMagicPoints()/2));
  if (!newbiep() && GetLevel() != 500 ) 
    foreach(string stat in GetStats() ) {
      if (!random(3)) AddStatLevel(stat, -1);
    }
}

int eventMove(mixed dest) {
  int ret = interactive::eventMove(dest);
  eventMoveFollowers(environment(this_object()));
  return ret;
}

varargs int eventMoveLiving(mixed dest, string omsg, string imsg) {
    object *inv, *enem;
    object prev;
    string prevclim, newclim;
   int x;
   int c;
   
    if( prev = environment() ) {
        prevclim = (string)prev->GetClimate();
        if( stringp(dest) ) {
            if(dest[0] != '/') {
                string *arr;

                arr = explode(file_name(prev), "/");
                dest = "/"+implode(arr[0..sizeof(arr)-2], "/")+"/"+dest;
            }
        }
        c = GetInCombat();
        
        if( !interactive::eventMove(dest) ) {
            eventPrint("You remain where you are.", MSG_SYSTEM);
            return 0;
        }
        inv = filter(all_inventory(prev), (: (!GetInvis($1) && living($1) && ($1 != this_object())) :));
        if( !omsg || omsg == "" ) omsg = GetMessage("telout");
        else omsg = GetMessage("leave", omsg);
        inv->eventPrint(omsg, MSG_ENV);
    }
    else if( !interactive::eventMove(dest) ) {
        eventPrint("You remain where you are.", MSG_SYSTEM);
        return 0;
    }
    inv = filter(all_inventory(environment()),(: (!GetInvis($1) && living($1) && ($1 != this_object())) :));
    if( (!imsg || imsg == "") && (!omsg || omsg == "") )
      imsg = GetMessage("telin");
    else if( !imsg || imsg == "" ) imsg = GetMessage("come", imsg);
    else imsg = replace_string(imsg, "$N", GetName());
    inv->eventPrint(imsg, MSG_ENV);
     if(GetInvis()) {
       AddStaminaPoints(-5);
       eventPrint("%^RED%^You move along quietly....%^RESET%^\n");
       AddExperience(5);
     }
    eventDescribeEnvironment(GetBriefMode());
    if (environment()->GetProperty("ocean") || environment()->GetProperty("shallows")) {
       eventPrint("You are %^BOLD%^BLUE%^swimming%^RESET%^!");
       AddStaminaPoints(-50);
       if (GetProperty("status") != "off") eventDisplayStatus();
      }  
    newclim = (string)environment()->GetClimate();
    if( !GetUndead() ) switch( newclim ) {
        case "arid":
            AddStaminaPoints(-0.3);
            AddDrink(-1);
            break;
        case "tropical":
            AddStaminaPoints(-0.3);
            break;
        case "sub-tropical":
            AddStaminaPoints(-0.2);
            break;
        case "sub-arctic":
            AddStaminaPoints(-0.2);
            break;
        case "arctic":
            AddStaminaPoints(-0.3);       
            break;
        default:
            AddStaminaPoints(-0.1);       
            break;          
    }
    if( prevclim != newclim && prevclim != "indoors" && newclim != "indoors" ){
        switch(prevclim) {
            case "arid":
                if( newclim == "tropical" || newclim == "sub-tropical" )
                  message("environment", "The air is much more humid.",
                          this_object());
                else message("environment", "The air is getting a bit cooler.",
                             this_object());
                break;
            case "tropical":
                if( newclim != "arid" )
                   message("environment", "The air is not quite as humid.",
                           this_object());
                else message("environment", "The air has become suddenly dry.",
                             this_object());
                break;
            case "sub-tropical":
                if( newclim == "arid" )
                  message("environment", "The air has become suddenly dry.",
                          this_object());
                else if( newclim == "tropical" )
                  message("environment","The air has gotten a bit more humid.",
                          this_object());
                else message("environment", "The air is not quite as humid.",
                             this_object());
                break;
            case "temperate":
                if( newclim == "arid" )
                  message("environment", "The air is a bit drier and warmer.",
                          this_object());
                else if( newclim == "tropical" )
                  message("environment", "The air is much more humid.",
                          this_object());
                else if( newclim == "sub-tropical" )
                  message("environment", "The air is a bit more humid.",
                          this_object());
                else message("environment", "The air is a bit colder now.",
                             this_object());
                break;
            case "sub-arctic":
                if( newclim == "arid" || newclim == "tropical" ||
                   newclim == "sub-tropical" )
                  message("environment", "It has suddenly grown very hot.",
                          this_object());
                else if( newclim == "arctic" )
                  message("environment", "It is a bit cooler than before.",
                          this_object());
                else message("environment", "It is not quite as cold as "
                             "before.", this_object());
                break;
            case "arctic":
                if( newclim == "sub-arctic" )
                  message("environment", "It is not quite as cold now.",
                          this_object());
                else message("environment", "It is suddenly much warmer than "
                             "before.", this_object());
        }
    }
    eventMoveFollowers(environment(this_player()));
    return 1;
}

int eventReceiveObject() {
    object ob;

    ob = previous_object();
    if( !ob || !interactive::eventReceiveObject() ) return 0;
    AddCarriedMass((int)ob->GetMass());
    return 1;
}

int eventReleaseObject() {
    object ob;

    ob = previous_object();
    if( !ob || !interactive::eventReleaseObject() ) return 0;
    if( ob->GetMass() )
    AddCarriedMass( -((int)ob->GetMass()) );
    return 1;
}

void eventLoadObject(mixed *value, int recurse) { }

mixed eventUse(object used, string cmd) {
    object old_agent;
    mixed tmp;

    old_agent = this_agent(used);
    tmp = parse_sentence(cmd);
    this_agent(old_agent);
    if( stringp(tmp) ) message("error", tmp, this_object());
    else return tmp;
}

/* *****************  /lib/player.c modal functions  ***************** */

int CanReceive(object ob) { return CanCarry((int)ob->GetMass()); }

mixed CanUse(object used, string cmd) { return 1; }

/* *****************  /lib/player.c local functions  ***************** */

int Setup() {
    if( !interactive::Setup() ) return 0;
    SetInvis(0);
    AddChannel( ({ "ooc",  }) );
    AddChannel( ({ "time" }) );
    AddChannel( ({ "reboot" }) );
    AddChannel( ({ "notify" }) );
    AddChannel( ({ "non" }) );
    AddChannel( ({ "quest" }) );
    AddChannel("hl");
    if (GetProperty("i3_enable")) { AddChannel("intergossip"); AddChannel("isport"); }
    if (GetProperty("i3_enable")) { AddChannel("fs"); AddChannel("dc"); }
    if (Story && !ApprovedStory) CHAT_D->eventSendChannel("STORY", "reports", "%^YELLOW%^" + GetCapName() + " has an unapproved story!%^RESET%^");
    set_heart_beat(GetHeartRate());
    SetShort("whatever");
    return 1;
}

/* ***************** /lib/player.c data functions  ***************** */

int GetSeveredHeads() { return SeveredHeads; }
int AddSeveredHead(int x) { eventPrint("%^YELLOW%^Head shot!%^RESET%^"); return SeveredHeads += x; }

int AddCarriedMass(int x) { return living::AddCarriedMass(x); }
int GetCarriedMass() { return living::GetCarriedMass(); }


string *SetLongDaemonData(string *d) { return LongDaemonData = d; }

varargs string *GetLongDaemonData(int x) { 
if (!LongDaemonData) {
LongDaemonData = ({ 0, 0, 0, 0, 0 });
}
if (x) return ({ LongDaemonData[x] });
return LongDaemonData;
}

int AddMagicPoints(int amount) {
  living::AddMagicPoints(amount);
  if (amount < 0) 
  if (GetProperty("status") != "off") eventDisplayStatus();
  return (GetMagicPoints());
  }

int AddCurrency(string type, int amount) {
    return living::AddCurrency(type, amount);
}

int AddBank(string bank, string type, int amount) {
    return living::AddBank(bank, type, amount);
}

string *SetTitles(string *titles) {
    if( sizeof(distinct_array(titles)) != sizeof(titles) ) return Titles;
    Titles = titles;
    SetShort("whatever");
}

string *AddTitle(string title) {
    if( !stringp(title) ) return Titles;
    else if( member_array(title, Titles) != -1 ) return Titles;
    else {
        Titles = ({ title }) + Titles;
        SetShort("whatever");
        return Titles;
    }
}

string *RemoveTitle(string title) {
    if( !stringp(title) ) return Titles;
    if( member_array(title, Titles) == -1 ) return Titles;
    else {
        Titles -= ({ title });
        SetShort("whatever");
        return Titles;
    }
}

string *GetTitles() { return Titles; }

int SetTitleAnd(int x) { return TitleAnd = x; }

int GetTitleAnd() { return TitleAnd; }

int SetTitleLength(int x) {
    if( x > 2 ) x = 2;
    return (TitleLength = x);
}

int GetTitleLength() { return TitleLength; }

string SetStory(string str) { 
if (ApprovedStory) {
return "Story has been approved already.  No changes made.";
}
return "Story set to: " + (Story = str); 
}

string GetStory() { return Story; }

int SetApprovedStory(int x) { return ApprovedStory = x; }

int GetApprovedStory() { return ApprovedStory; }

int GetQuestCompleted(string desc) {
  foreach(class quest q in Quests) {
    if (q->Description == desc) return 1;
    }
  return 0;
}

mixed RemoveQuest(string desc) {
  if (!desc) return 0;
  foreach(class quest q in Quests) {
    if (q->Description == desc) Quests -= ({ q });
  }
  return Quests;
}

void AddQuest(string title, string desc)
{
  class quest tmp;

  if (!desc) return;
  if (GetQuestCompleted(desc)) {
    eventPrint("You have previously completed this quest.");
    return;
    }
  tmp = new(class quest);
  tmp->Date = time();
  tmp->Description = desc;
  Quests += ({ tmp });
  CHAT_D->eventSendChannel("Quest", "quest", capitalize(GetKeyName()) + 
                           " has completed the quest " + desc);
  if (title) AddTitle(title);
  log_file("players/quests", GetKeyName() + " completed " + desc + " : " + ctime(time()) + "\n");
}

mixed *GetQuests()
{
  return map(Quests, (: ({ ((class quest)$1)->Date,
                           ((class quest)$1)->Description }) :));
}

string SetOOCName(string str) {
  return (OOCName = str);
  }

string GetOOCName() {
  if (!OOCName) return capitalize(GetKeyName());
  return (OOCName);
 }

int SetNoRank(int x) { NoRank = x; SetShort(""); return NoRank; }
int GetNoRank()      { return NoRank; }

string SetSurname(string str) { return Surname = str; }
string GetSurname() { return Surname; }

string SetShort(string irrelevant) {
    string title;
    int i;

  if (!sizeof(Titles) || (strsrch(Titles[0], "$N") == -1)) {
    title = "$N ";
    } else title = "";
  if( !(i = sizeof(Titles)) )
    title += "the unaccomplished";
    else title += Titles[0];
  if (i > 1) {
    if (strsrch(Titles[1], "$N") == -1) {             
      if( TitleLength > 1 && TitleAnd == 1) title += " and " + Titles[1];
      if( TitleLength > 1 && TitleAnd == 0) title += " " + Titles[1];
    }
  }
  if (!GetNoRank()) title = GetRank() + " " + title;
  title = title + " (" + GetNationality() + " " + GetRace() + ")";
  if (GetUndead()) title += " (undead)";
  return interactive::SetShort(title);
}

string GetFullShort() {
    string title;
    int i;

  if (!sizeof(Titles) || (strsrch(Titles[0], "$N") == -1)) {
    title = "$N ";
    } else title = "";
  if( !(i = sizeof(Titles)) )
    title += "the unaccomplished";
    else title += Titles[0];
  if (i > 1) {
    if (strsrch(Titles[1], "$N") == -1) {             
      if( TitleLength > 1 && TitleAnd == 1) title += " and " + Titles[1];
      if( TitleLength > 1 && TitleAnd == 0) title += " " + Titles[1];
    }
  }
  if (!GetNoRank()) title = GetRank() + " " + title;
  title = title + " (" + GetNationality() + " " + GetRace() + ")";
  title = replace_string(title, "$N", capitalize(GetKeyName()));
  return title;
}

string *GetFriends() {
     return ({ });
   }

int SetUndead(int x) {
    if (GetUndead()) RemoveAdditionalId(GetUndeadType());
    x = living::SetUndead(x);
    if (x) SetAdditionalId(GetUndeadType());
    SetShort("nonsense");
    return x;
}

string GetName() {
  string n;
   if (GetUndead()) return "a " + GetUndeadType();
   if(GetInvis()) return "a shadow";
   if (GetSurname()) {
     if (GetTown() == "Tairi")
       return n = Surname + " " + interactive::GetName(); 
       else return n = interactive::GetName() + " " + Surname;
   } else return interactive::GetName();
}

varargs string GetRawLong() { return interactive::GetLong(); }


varargs string GetLong(string str) {
    mapping counts;
    string item;

    str = GetShort() + "\n";
    if (GetExternalDesc() != "$N is nondescript.") {
      //RawDesc is ExternalDesc with $N interpreted.
      str += GetExternalDesc() + "\n";
    } else {
      //autogenerated description
      str += DESCRIPTION_D->GetLong(this_object()) + "\n";
    }

    // I don't even know if living possesses a GetLong. >_>
    str += living::GetLong(nominative(this_object()));

    // damned if I know anything with "GetAffectLong"
    foreach(item in map(all_inventory(),
      (: (string)$1->GetAffectLong(this_object()) :))) {
      if( item ) str += item + "\n";
    }
    counts = ([]);

    // I altered this to only include worn inventory.
    foreach(item in map(
        filter(all_inventory(),
        (: !((int)$1->GetInvis(this_object())) && ((int)$1->GetWorn()) :)),
        (: (string)$1->GetEquippedShort() :))) {
      if( item ) counts[item]++;
    }
    if( sizeof(counts) ) str += GetCapName() + " is adorned with:\n";
    foreach(item in keys(counts)) {
      str += capitalize(consolidate(counts[item], item)) + "\n";
    }
    //TODO: add first shield
    return str;
}
string GetCapName() { return interactive::GetCapName(); }

string GetShort() {
    if (GetViking()) {
      return capitalize(GetKeyName()) + " the Viking (bork bork bork)";
      }
  return ::GetShort();
}

int ResetLevel() {
  int x, y;
  string *stats = ({});

  x = GetLevel();
  if (x >= 20 && !ApprovedStory && !TestChar) {
  eventPrint("You must have an approved character story to advance further.");
  eventPrint("See \"help story\" for more information.");
  return x;
  }
  if (x >= 8 && !GetLongDaemonData(0)[0] && !TestChar) {
  eventPrint("You must have used the \"describe\" command before being "
             "allowed to advance any further.");
    return x;
    }
  if (x >= 24 && sizeof(GetPrimarySkills()) == 1 && !TestChar) {
    eventPrint("You cannot become a high mortal with only one primary.");
    eventPrint("Get more skills to advance!");
    return x;
    }
  if (x >= 49 && sizeof(GetPrimarySkills()) <= 3 && !TestChar) {
    eventPrint("You cannot become a legend with 3 or less primaries.");
    return x;
  }
  if (x >= 99 && sizeof(GetPrimarySkills()) <= 4  && !TestChar) {
    eventPrint("You cannot become an Avatar with 4 or less primaries.");
    return x;
  }
  if (x >= 249 && sizeof(GetPrimarySkills()) <= 5 && !TestChar) {
    eventPrint("You cannot become a Demi God with 5 or less primaries.");
    return x;
    }
  if( x != (y = living::ResetLevel()) ) {
    string file = "players/levels";
    if (x >= 500) {
     if (!GetTestChar()) {
       eventPrint("You win!");
       users()->eventPrint("%^BOLD%^BLACK%^" + capitalize(GetKeyName()) + " has reached level 500!%^RESET%^");
     }
     return x;
    }    
    if( x < y ) {
      eventPrint("%^YELLOW%^You feel a surge of power as you reach a new level of accomplishment.%^RESET%^");
      LastLevel = time();
      if (y > HighestLevel) {
        AddDevelopmentPoints((y-x) * 2);
        if (random(100) < 6) {
          eventPrint("%^YELLOW%^BOLD%^You gain a stat customization point.%^RESET%^");
          AddCustomStats(1);
          stats += ({ "%^YELLOW%^custom%^RESET%^" });
        }
        foreach(string stat in GetStats()) {
          if (GetBaseStatLevel(stat) < 125) {
            int chance = 0;
            chance = 103 - (GetStatClass(stat) * 20);
            if (GetLastDeath() > GetLastLevel()) chance += 33;
            chance -= (GetStatLevel(stat)/3);
            if (chance > 60) chance = 60;
            if (chance <  3) chance = 3;
  // if (GetTestChar()) debug(stat + ": " + GetBaseStatLevel(stat) + "(" + GetStatClass(stat) + ") = " + chance);
            if (random(100) <= chance) {
              AddStatLevel(stat, 1);
              stats += ({ stat });
              }
          }
          
        }
        if (!sizeof(stats)) {
        string stat = GetStats()[random(sizeof(GetStats()))];
          if (GetTestChar()) debug("random stat!");
          AddStatLevel(stat, 1);
          stats += ({ stat });
        }
        HighestLevel = y;
     } 
     if (x == 4 && y == 5) {
      eventPrint("You receive a torch!");
      new(STD_LIGHT "torch")->eventMove(this_object());
      }
     CHAT_D->eventSendChannel("Level Attained", "reports", capitalize(GetKeyName()) + " advanced to level " + y + ". Gained : " + conjunction(stats, "and") );
     if (y >= 400) CHAT_D->eventSendChannel("Epic Advancement", "ooc",
        capitalize(GetKeyName()) + " advanced to level " + y + ".");
    }
    SetShort("whatever");
  }
  if (y >= 25 && CHARACTER_D->CanAdvancedStart(GetEmail()) != 1) {
    eventPrint("%^BOLD%^BLUE%^You now have access to advanced starting towns and races.%^RESET%^");
    CHARACTER_D->AddAdvancedStart(GetEmail());
  }
  return y;
}

int GetHighestLevel() { return HighestLevel; }

int SetHighestLevel(int x) { return HighestLevel = x; } // This a way for Duuk to reset someone.

int GetLastLevel() { return LastLevel; }


int GetEffectiveVision() {
    if( newbiep(this_object()) ) return VISION_CLEAR;
    if( GetBlind() ) return VISION_BLIND;
    else return living::GetEffectiveVision();
}

varargs int AddHealthPoints(int x, string limb, object agent) {
    int hp, ret, undead;

    hp = GetHealthPoints();
    undead = GetUndead();
    ret = living::AddHealthPoints(x, limb, agent);
    if( hp <= (hp = GetHealthPoints()) || undead != GetUndead() ) return ret;
    if (GetProperty("status") != "off") eventDisplayStatus();
    return ret;
}

int GetLanguageLevel(string lang) {
    if( newbiep() ) return 100;
    else return living::GetLanguageLevel(lang);
}

mapping *GetDeaths() {
    if( !Deaths ) return ({});
    return map(Deaths, function(class death morte) {
                           return ([ "date" : morte->Date,
                                    "enemy" : morte->Enemy ]);
                       });
}

int GetLastDeath() {
  int x = 0;
  foreach(mapping dd in GetDeaths()) 
    if (dd["date"] > x) x = dd["date"];
  return x;
}

int AddDevelopmentPoints(int x) {
    CHAT_D->eventSendChannel("DP", "players", capitalize(GetKeyName()) + " gained " + x + " Dev Points.");
    eventPrint("%^YELLOW%^Development Point Change of " + x + ".%^RESET%^");
    return (DevelopmentPoints += x);
}
 
int RemoveDevelopmentPoints(int x) {
    CHAT_D->eventSendChannel("DP", "players", capitalize(GetKeyName()) + " gained " + x + " Dev Points.");
    eventPrint("%^YELLOW%^Development Point Change of " + x + ".%^RESET%^");
    return (DevelopmentPoints -= x);
} 

int GetDevelopmentPoints() { return DevelopmentPoints; }

string *GetExploredWorlds() { return ExploredWorlds; }

string *AddExploredWorld(string world) {
world = capitalize(world);
if (member_array(world, ExploredWorlds) == -1) {
eventPrint(world + " is a new world for you to explore!");
AddDevelopmentPoints(6);
ExploredWorlds += ({ world });
}
return ExploredWorlds;
}

string *RemoveExploredWorlds(string *worlds) {
if (!arrayp(worlds)) worlds = ({ worlds });
ExploredWorlds -= worlds;
return ExploredWorlds;
}

varargs int eventTrain(string skill, int points) {
    float x = 0;
    mapping mp;
 
    if( points < 1 ) points = 1;
    if( !(mp = GetSkill(skill)) ) return 0;
    if( DevelopmentPoints < points ) return 0;
    while( points-- ) {
        int max = GetMaxSkillPoints(skill, mp["level"]);
        switch( mp["class"] ) {
            case 1: x = 50.0; break;
            case 2: x = 40.0; break;
            case 3: x = 30.0; break;
            case 4: x = 20.0; break;
            default: return 0;
        }
        AddDevelopmentPoints(-1);
        
    }
    return 1;
}

/*
mixed direct_ask_liv_str() {
  return "You cannot use the ask verb on a character.";
  }

mixed direct_ask_liv_to_str() {
  return "You cannot use the ask verb on a player.";
}
*/

int SetTellRestricted(int i) { return TellRestricted = i; }

int GetTellRestricted() { return TellRestricted; }

void eventCompleteHeal(int amount) {
  living::eventCompleteHeal(amount);
  if (GetHealthPoints() != GetMaxHealthPoints() ||
      GetStaminaPoints() != GetMaxStaminaPoints() ||
      GetMagicPoints() != GetMaxMagicPoints() ) {
  if (GetProperty("status") != "off") eventDisplayStatus();
 }
}

mixed SetPermanentProperty(string prop, mixed arg) {
   return PermanentProperties[prop] = arg;
}

mixed GetProperty(string prop) {
  if (interactive::GetProperty(prop)) return interactive::GetProperty(prop);
  return PermanentProperties[prop];
}

mapping GetProperties() {
  return interactive::GetProperties() + PermanentProperties;
}

int RemovePermanentProperty(string prop) {
  if (undefinedp(PermanentProperties[prop])) return 1;
  map_delete(PermanentProperties, prop);
  return !PermanentProperties[prop];
}

static int cmdAll(string args) {
  if (GetHiding()) SetHiding(0);
  return ::cmdAll(args);
}

int GetInvis() { 
  if (GetHiding()) return 1;
  if (GetUndeadType() == "ghost") return 1;
  return ::GetInvis();
}

string *SetImprovedStats(string *x) {
  return ImprovedStats = x;
}

string *AddImprovedStat(string x) {
  ImprovedStats = distinct_array(ImprovedStats + ({ x }) );
  return ImprovedStats;
}

string *GetImprovedStats() { 
  return ImprovedStats;
}

int GetImprovedStat(string stat) {
  if (member_array(stat, ImprovedStats) != -1) return 1;
  return 0;
}

string *GetPartyMembers() { return filter(PartyMembers, (: $1 :) ); }
 
string *GetCapitalPartyMembers() {
  string *tmp = ({ });
  foreach(string i in PartyMembers) { tmp += ({ capitalize(i) }); }
  return tmp;
}

string *AddPartyMember(string who) { 
  if (lower_case(who) == GetKeyName()) return ({ });
  PartyMembers = distinct_array(PartyMembers + ({ lower_case(who) })); 
  eventPrint("%^BOLD%^MAGENTA%^" + capitalize(who) + " added to your party.%^RESET%^");
  return PartyMembers;
}

string *RemovePartyMember(string who) { 
  PartyMembers = distinct_array(PartyMembers - ({ lower_case(who) })); 
  eventPrint("%^BOLD%^MAGENTA%^" + capitalize(who) + " removed from your party.%^RESET%^");
  return PartyMembers;
}


int AddPartyExperience(int x) {
  return ::AddExperience(x);
}

int AddExperience(int x) {
  object *party = ({ });
  foreach(string party_member in PartyMembers) {
    if (find_player(party_member)) { 
      party += ({ find_player(party_member) }); 
    } else { 
      RemovePartyMember(party_member); 
    }
  }
  party += ({ this_object() });
  if (x < 0) { AddPartyExperience(x); return x; }
  
  x = x/sizeof(party);
  if (sizeof(party) > 1) eventPrint("%^YELLOW%^**%^RESET%^You are sharing experience with " + conjunction(GetCapitalPartyMembers(), "and") + ".");
  foreach(object m in party) { m->AddPartyExperience(x); }
  return x;
}
// Mahkefel december 2011: code for combat actions
// returns the amount of berserker fury, derring-do, or
//  whatever the player has built up.
string GetCombatActionDescriptions() {
  string output = "";

  foreach(object shiny in all_inventory(this_object()) ) {
    if (shiny->GetCombatActionDescription()) {
      output += shiny->GetCombatActionDescription();
    }
  }

  if (output == "") return 0;
  return output;
}
