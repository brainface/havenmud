/* 
 * major_room_ward.c
 * ward object for warding type spells
 * balishae@haven
 * 4/98
 * minor changes made to relect use with the enhanced alarm spell
 * Dylanthalus@Haven
 */
 

#include <lib.h>

inherit LIB_ITEM;

// Prototypes
string  SetMaster(string master);
int             SetCountDown(int timeLImit);
int             GetCountDown();
void    DoFade();

// Global Variables
string Master = "";
int countDown;



static void create()
{
        item::create();
        SetKeyName("room ward");
        SetId( ({"ward",}) );
        SetAdjectives( ({"room",}) );
        SetShort("a ward");
        SetLong("An invisible ward.");
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
                if(who = find_player(Master))
                {
                        message("ward message",
                        "%^BOLD%^%^BLUE%^Your enhanced alarm at " +
                        environment()->GetShort() + 
                        "%^BOLD%^%^BLUE%^ has been activated by " + 
                        this_player()->GetCapName() + ".%^RESET%^",
                        who);
                }
                else
                eventDestruct();
        }
}

void heart_beat()
{
        countDown--;
        if(!countDown) { DoFade(); }
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
        if(who = find_player(Master))
        message("ward message",
        "%^BOLD%^%^BLUE%^Your enhanced alarm " +
        environment()->GetShort() + " fades out of existance.%^RESET%^",
        who);
        
        eventDestruct();
}
