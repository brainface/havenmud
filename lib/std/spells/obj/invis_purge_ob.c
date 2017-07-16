#include <lib.h>

inherit LIB_ITEM;

string  SetMaster(string master);
int     SetCountDown(int timeLImit);
int     GetCountDown();
void    DoFade();
void    DoPurge();
string  Master = "";
int     countDown;

static void create()
{
        item::create();
        SetKeyName("invisibility purge field");
        SetId( ({"field",}) );
        SetAdjectives( ({"room",}) );
        SetShort("a field");
        SetLong("An invisible purging field.");
        SetInvis(1);
        SetMass(1);
        SetValue(0);
        SetDamagePoints(5);
        SetPreventGet("There is nothing tangible to get.");
        set_heart_beat(1);
}

void init()
{
        object who;
        
        if(this_player()->GetKeyName() != Master &&
           !(immortalp(this_player())))
        {           
        if(this_player()->GetInvis()) {
                        this_player()->SetInvis(0);   
                        message("ward message",
                        "%^BOLD%^%^BLUE%^The magics around you are stripped away and you "
                        "suddenly fade into view.%^RESET%^",
                        this_player());
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
        "%^BOLD%^%^BLUE%^Your invisibility purging field fades out of existence at " + room3->GetShort() +        
".%^RESET%^",who);
        
        eventDestruct();
}


void DoPurge(){
  object array critter = ({ });
  object who;
  who = find_player(Master);
  
   critter = filter(all_inventory(environment(this_object())), (: living($1) && noncreatorp($1) :) );
   critter = critter - ({ who });  
   foreach(object person in critter){
       if(person->GetInvis()){
            message("ward message",
                        "%^BOLD%^%^BLUE%^The magics around you are stripped away and you "
                        "suddenly fade into view.%^RESET%^",
                        critter);
                  critter->SetInvis(0); 
      }
    }
}

