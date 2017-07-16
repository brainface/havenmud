/*    /lib/meal.c
 *    from the Nightmare IV LPC Library
 *    standard food and drink code
 *    created by descartes of Borg 950603
 *    Version: @(#) meal.c 1.2@(#)
 *    Last modified: 96/10/12
 */
 
#include <lib.h>
#include <function.h>
#include <meal_types.h>
#include <rounds.h>
#include <vendor_types.h>
#include "include/meal.h"
 
inherit LIB_BAIT;
inherit LIB_ITEM;
 
private int MealStrength, MealType, DecayCall, DecayTime, Portions;
private int Lit;
private string EmptyItem, EmptyName, OtherMessage;
private string Long, Short;
private mixed EmptyShort, EmptyLong, MyMessage;
 
static void create() {
    item::create();
    SetValue(-1);
    MealType = MEAL_DRINK;
    DecayTime = 0;
    EmptyItem = 0;
    Portions = 1;
    Lit = 0;
    EmptyName = "bottle";
    EmptyShort = "an empty bottle";
    EmptyLong = "This empty bottle once contained some alcohol.";
    MyMessage = "You drink your drink.";
    OtherMessage = "$N drinks $P drink.";
    SetVendorType(VT_DRINK);
    if (DecayTime) DecayCall = call_out( (: eventDecay :), DecayTime);
    AddSave( ({ "MealStrength", "MealType", "Portions" }) );
    AddSave( ({ "Long", "Short" }) );

    set_heart_beat(60);
}

void heart_beat() {
  object who = environment();
  if (!who) return;
  if (GetLit()) {
    who->eventPrint(capitalize(GetShort()) + " slowly %^RED%^burns.%^RESET%^");
    if (Portions == 1) {
      who->eventPrint(capitalize(GetShort()) + " burns down to nothing.");
    }
    AddPortion(-1, who);
  }
}

mixed direct_light_obj() {
  if (!(MealType & MEAL_SMOKE)) return "You don't want to light that.  Really.";
/*  return "You need to light this with a match."; */

/* Editted under the new assumptions that all players have a 
   utility pack holding basic items like matches. Made to
   light without a match obj. - Melchezidek 11/25/07 */
   
  if (GetLit()) return "But " + GetShort() + " is already lit!";
  return 1;
}

mixed direct_light_obj_with_obj() {
  if (!(MealType & MEAL_SMOKE)) return "You don't want to light that.  Really.";
  if (GetLit()) return "But " + GetShort() + " is already lit!";
  return 1;
}

mixed direct_darken_obj() {
  if (!(MealType & MEAL_SMOKE)) return 0;
  if (!GetLit()) return "But that isn't lit!";
  return 1;
}

mixed direct_drink_obj() { 
    if( environment() != this_player() ) return "#You don't have that!";
    if( MealType & MEAL_FOOD ) return "Wouldn't you rather eat it?";
    return (int)this_player()->CanDrink(this_object());
}

mixed direct_smoke_obj() { 
    if( environment() != this_player() ) return "#You don't have that!";
    if(!(MealType & MEAL_SMOKE)) return "But that is not something you smoke!";

    if (!GetLit()) return "But it isn't lit!";
    return (int)this_player()->CanSmoke(this_object());
}

mixed direct_drink_from_obj() {
    if( MealType & MEAL_FOOD ) return 0;
    if( environment() != environment(this_player()) &&
       (environment() != this_player()) ) 
       return "#That is not here!";
    return (int)this_player()->CanDrink(this_object());
}

mixed direct_eat_obj() {
    if( environment() != this_player() ) return "#You don't have that!";
    if( !(MealType & MEAL_FOOD) ) return "Wouldn't you rather drink it?";
    return (int)this_player()->CanEat(this_object());
}

static mixed AddSave(mixed *vars) { return item::AddSave(vars); }


int eventDestruct() { return item::eventDestruct(); }

mixed eventDrink(object who) {
    mixed tmp;
    int x;
 
    if( (tmp = (mixed)who->eventDrink(this_object())) != 1 ) return tmp;
    if( (x = functionp(MyMessage)) && !(x & FP_OWNER_DESTED) ) {
            evaluate(MyMessage, who);
      }
      else {
        string mymsg, othermsg;
        mymsg = replace_string(MyMessage, "$P", "your");
        othermsg = replace_string(OtherMessage, "$P", possessive(who));
        mymsg = replace_string(mymsg, "$N", "you");
        othermsg = replace_string(othermsg, "$N", (string)who->GetName());
        who->eventPrint( capitalize(mymsg) );
        environment(who)->eventPrint( capitalize(othermsg), who );
    }

    if( x = GetPoison() > 0 ) {
        if( random((int)who->GetStatLevel("luck")) > 35 )
            who->eventPrint("That didn't seem to taste quite right.");
        who->AddPoison(x);
    }
    AddPortion(-1, who);
    return 1;
}

mixed eventSmoke(object who) {
    mixed tmp;
    int x;
 
    if( (tmp = (mixed)who->eventSmoke(this_object())) != 1 ) return tmp;
    if( (x = functionp(MyMessage)) && !(x & FP_OWNER_DESTED) ) {
            evaluate(MyMessage, who);
      }
      else {
        string mymsg, othermsg;
 
        mymsg = replace_string(MyMessage, "$P", "your");
        othermsg = replace_string(OtherMessage, "$P", possessive(who));
        mymsg = replace_string(mymsg, "$N", "you");
        othermsg = replace_string(othermsg, "$N", (string)who->GetName());
        who->eventPrint( capitalize(mymsg) );
        environment(who)->eventPrint( capitalize(othermsg), who );
    }
    if( x = GetPoison() > 0) {
        if( random((int)who->GetStatLevel("luck")) > 35 )
            who->eventPrint("That didn't seem to taste quite right.");
        who->AddPoison(x);
    }
    AddPortion(-1, who);
    return 1;
}

 
mixed eventEat(object who) {
    mixed tmp;
    int x;
 
    if( (tmp = (mixed)who->eventEat(this_object())) != 1 ) return tmp;
    if( (x = functionp(MyMessage)) && !(x & FP_OWNER_DESTED) ) {
        evaluate(MyMessage, who);
    }
    else {
        string mymsg, othermsg;
        mymsg = replace_string(MyMessage, "$P", "your");
        othermsg = replace_string(OtherMessage, "$P",
                                  possessive(who));
        mymsg = replace_string(mymsg, "$N", "you");
        othermsg = replace_string(othermsg, "$N", (string)who->GetName());
        who->eventPrint( capitalize(mymsg) );
        environment(who)->eventPrint( capitalize(othermsg), who );
    }
    if( x = GetPoison() > 0) {
        if( random((int)who->GetStatLevel("luck")) > 35 )
            who->eventPrint("You notice a strange aftertaste.");
        who->AddPoison(x);
  if (DecayCall)  remove_call_out(DecayCall);
    }
    AddPortion(-1, who);
    return 1;
}
 
int eventPoison(object who, object agent, int x) {
    who->eventPrint("You put some poison "
                    "in " + add_article(GetShort()) + ".");
    environment(who)->eventPrint( (string)who->GetName()+" puts something "
                      "in " + add_article(GetShort()) + ".", who);
    AddPoison(x);
    return 1;
}

int eventLight(object who, object match) {
  SetLit(1);
  return 1;
}

int eventDarken() {
  send_messages( "extinguish", "$agent_name $agent_verb " + GetShort() + ".", this_player(), 0, environment(this_player()));
  SetLit(0);
}  

int SetLit(int x) { return Lit = x; }
int GetLit() { return Lit; } 

string SetEmptyItem(string file) { return (EmptyItem = file); }
 
string GetEmptyItem() { return EmptyItem; }
 
string SetEmptyName(string str) { return (EmptyName = str); }
 
string GetEmptyName() { return EmptyName; }
 
mixed SetEmptyShort(mixed val) { return (EmptyShort = val); }
 
mixed GetEmptyShort() { return EmptyShort; }
 
mixed SetEmptyLong(mixed val) { return (EmptyLong = val); }
 
mixed GetEmptyLong() { return EmptyLong; }
 
int SetMealType(int x) {
    int vt = 0;
 
    if( x & MEAL_FOOD ) {
        vt |= VT_FOOD;
        MyMessage = "You eat " + GetShort() + ".";
        OtherMessage = "$N eats " + GetShort() + ".";
    }
    if( x & MEAL_DRINK ) {
      vt |= VT_DRINK;
      MyMessage = "You drink " + GetShort() + ".";
      OtherMessage = "$N drinks " + GetShort() + ".";
      }
    if( x & MEAL_SMOKE ) {
      vt |= VT_SMOKE;
      MyMessage = "You smoke " + GetShort() + ".";
      OtherMessage = "$N smokes " + GetShort() + ".";
      }
    if (!(x & MEAL_FOOD) && !(x & MEAL_DRINK) && !(x & MEAL_SMOKE)) {
        error("**Need to set to either MEAL_FOOD or MEAL_DRINK.");
        return -1;
    }
    
    SetVendorType(vt);
    return (MealType = x);
}
 
int GetMealType() { return MealType; }
 
int SetStrength(int x) { return (MealStrength = x); }
 
int GetStrength() { return MealStrength; }
 
varargs void SetMealMessages(mixed array val...) {
    if( !arrayp(val) ) {
        error(sprintf("Bad argument 1 to SetMealMessages(): %O\n", val));
    }
    if( sizeof(val) == 1 ) {
        if( arrayp(val[0]) ) SetMealMessages(val[0]...);
        else if( stringp(val[0]) || functionp(val[0]) ) MyMessage = val[0];
        else error(sprintf("Bad argument 1 to SetMealMessages(): %O\n",
                           val[0]));
        return;
    }
    if( !stringp(val[0]) )
      error(sprintf("Bad argument 1 to SetMealMessages(): %O\n", val[0]));
    else if( !stringp(val[1]) ) 
      error(sprintf("Bad argument 2 to SetMealMessages(): %O\n", val[1]));
    MyMessage = val[0];
    OtherMessage = val[1];
}
 
mixed *GetMealMessages() { return ({ MyMessage, OtherMessage }); }
  int GetValue() {
  int x;
  
  if (item::GetValue() == -1) {
    x = GetStrength() * GetPortions();
    return (x /10) + 10;
  }
  return item::GetValue();
}

int SetDecayTime(int x) {
   DecayCall = call_out( (: eventDecay :), x);
    return (DecayTime = x);
  }

int GetDecayTime() {
   return (DecayTime);
  }

static void eventDecay() {
    message("decay", GetShort() + " decays to nothing.", environment());
    remove_call_out(DecayCall);
  Destruct();
  }

string SetLong(string str) {
  Long = str;
  return item::SetLong(str);
  }

string SetShort(string str) {
  Short = str;
  return item::SetShort(str);
  }

string GetLong() { 
         return Long;
         }

string GetShort() {
  string sh = ::GetShort();
  if (GetLit()) { return sh + " (lit)"; }
  return sh;
}

string GetItemCondition() { 
        string tmp = "\nThere ";
  if (GetPortions() > 1) tmp += "are "; else tmp += "is ";
  tmp += consolidate(GetPortions(), "one portion");
  tmp += " left.";
        if (GetPortions() == -1) return "";
        return tmp; 
}

int SetPortions(int x) { return Portions = x; }
int GetPortions() { return Portions; }

varargs int AddPortion(int x, object who) {
        if (Portions == -1) return 1;
        if ((Portions += x) <= 0) {
                if (who) who->eventPrint(capitalize(GetShort()) + " is entirely used up.");
                if( GetEmptyItem() ) {
        object ob;
 
        ob = new(GetEmptyItem() || LIB_ITEM);
        if( base_name(ob) == LIB_ITEM ) {
            ob->SetKeyName(GetEmptyName());
            ob->SetId( ({ GetEmptyName(), "container", "empty container" }) );
            ob->SetShort(GetEmptyShort());
            ob->SetLong(GetEmptyLong());
            ob->SetValue(5);
            ob->SetMass(GetMass());
            ob->SetDestroyOnSell();
            ob->eventMove(who);
        }
      }
                Destruct();
        }
        return 1;
}
mixed direct_store_obj() {
    if( environment() != this_player() ) return "#You don't have that!";
    if( member_array("fish",GetId()) == -1 ) return "This isn't a fish!";
    return 1;
}

