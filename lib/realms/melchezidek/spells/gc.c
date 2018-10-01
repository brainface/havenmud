#include <lib.h>
#include <damage_types.h>

inherit LIB_ITEM;

string  SetMaster(string master);
int     SetCountDown(int timeLImit);
int     GetCountDown();
void    DoFade();
void    DoPurge();
string  Master = "";
int     countDown;
int     Damage;
int SetDamageAmount(int damage);

static void create()
{
        item::create();
        SetKeyName("great circle");
        SetId( ({"circle",}) );
        SetAdjectives( ({"large", "great", "chalk"}) );
        SetShort("a large chalk circle");
        SetLong("This large circle glows with holy power. It is drawn to so "
        "that it surrounds the room. It is made with pure white chalk dust, though "
        "it looks like it could be easily destroyed or removed, it remains perfectly "
        "untouched.");
        SetMass(1);
        SetValue(0);
        SetDamagePoints(5);
              SetProperty("gcircle", 1);
        SetPreventGet("You cannot pick that up!");
        set_heart_beat(5);
}

void init()
{
        object who;
        
        if(this_player()->GetKeyName() != Master &&
           !(immortalp(this_player())) && (!newbiep(this_player())))
        {           
        if(this_player()->GetMorality() < -200 || this_player()->GetUndead() == 1) {
           message("ward message",
                   "%^BOLD%^%^RED%^The chalk circle glows red as " + this_player()->GetName() +
                   " steps into the room.%^RESET%^",
                        environment());        
              if(userp(this_player())){
                 this_player()->eventWimpy();
             }
          Damage = Damage/5;  
          if (Damage <= 0) Damage = 1;
          debug("GCircle Damage: " + Damage);      
          this_player()->eventReceiveDamage(this_object(), HEAT|MAGIC|SHOCK, Damage, 0);
         }
        }
}

void heart_beat()
{

    object room;
    object who;
    
    room = environment(this_object());

    if (!room) {
     eventDestruct();
     return;
    }  
    if(!who = find_player(Master)){
   room->RemoveProperty("great_circle");
     eventDestruct();
     return;
    }    
        countDown--;
        if(!countDown) { DoFade(); }
        else {

        return DoPurge();
        }
}

string SetMaster(string master)
{
        return (Master = master);
}

int SetCountDown(int timeLimit)
{
        return (countDown = timeLimit);
}

int SetDamageAmount(int damage){
        return (Damage = damage);
}

int GetCountDown()
{
        return countDown;
}

void DoFade()
{
        object who;
        object room3;

        room3 = environment(this_object());
        if(who = find_player(Master))
        message("ward message",
        "%^BOLD%^%^BLUE%^Your Great Circle fades out "
        "of existence at " + room3->GetShort() + ".%^RESET%^",who);
        
        room3->RemoveProperty("great_circle");
        eventDestruct();
}


void DoPurge(){
  object *critters;
  object who;
  who = find_player(Master);
  
  critters = filter(all_inventory(environment(this_object())), (: living($1) && !newbiep($1) :));
  critters = filter(critters, (: noncreatorp :) );
  critters -= who->GetEnemies();
      message("ward message",
              "%^BOLD%^%^WHITE%^The chalk circle glows white " 

              "briefly.%^RESET%^", environment());
         critters->eventHealDamage(Damage, 1); 
}
