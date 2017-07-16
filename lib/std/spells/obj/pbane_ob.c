// poison field
// Thoin
// 1-25-06
 
#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>
#include <meal_types.h>
inherit LIB_ITEM;

int SetCountDown(int timeLimit);
int GetCountDown();
int GetDamageAmount();
string GetMaster();
void DoFade();
void DoHeal();
int countDown;
int Damage;
string SetMaster(string master);
int SetDamageAmount(int damage);

string Master = "";

static void create(){
        item::create();
        SetKeyName("poison field");
        SetId( ({"invis_poison_thing"}) );
        SetShort("invis poison thing");
        SetLong("invisible poisoning object.");
        SetMass(1);
        SetInvis(1);
        SetValue(0);
        SetDamagePoints(5);
        SetPreventGet("You cannot pick that up!");
        set_heart_beat(5);
}

void heart_beat(){
    object room;
   object who;
    room = environment(this_object());

    if (!room) {
     eventDestruct();
     return;
    }  
    if(!who = find_player(Master)){
     return DoFade();
    }
        countDown--;
        if(!countDown) { DoFade(); }
        else {
        return DoHeal();
        }
}

string SetMaster(string master){
        return (Master = master);
}

int SetDamageAmount(int damage){
        return (Damage = damage);
} 

int SetCountDown(int timeLimit){
        return (countDown = timeLimit);
}

int GetCountDown(){
        return countDown;
}

int GetDamageAmount(){
        return Damage;
}

string GetMaster(){
        return Master;
}

void DoFade(){
        object room;
        room = environment(this_object());
        
        environment(this_object())->eventPrint("%^BOLD%^%^BLUE%^The air "
        "returns to normal.%^RESET%^", room);
        room->RemoveProperty("poison_field");
        eventDestruct();
}

void DoHeal(){
  object *critters;
  int num = find_player(Master)->GetSkillLevel("necromancy")/20;
  
  if(environment())
  critters = filter(all_inventory(environment(this_object())), (: living($1) :));
critters = filter(critters, (: noncreatorp :) );

  message("my_message", "%^BOLD%^%^BLACK%^A small fly buzzes around you.%^RESET%^"
         ,environment());

for(int i=0;i<num;i++) {
      object target = (critters[random(sizeof(critters))]);
      object array eq = all_inventory(target);
    if(sizeof(eq)) {
      object thing = (eq[random(sizeof(eq))]);
         if(thing->GetMealType()) {
            thing->SetPoison(num);
      } else { return; }
    }
   }
 return;
}

