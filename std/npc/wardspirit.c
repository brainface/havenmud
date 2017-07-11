#include <lib.h>

inherit LIB_NPC;

string spiritMaster,spiritTarget;


string CheckMaster();
string CheckTarget();
string SetMaster(object who);
string SetTarget(object who);
void StartTime(int duration);

static void create()
{
  npc::create();
  SetKeyName("wardspirit");
  SetId( ({ "wardspirit"}) );
  SetShort( "a wispy spirit" );
  SetLong( "The wispy wardspirit floats patiently here." );
  SetLevel(1);
  SetRace("elemental");
  SetClass("valkyr");
  SetGender("neuter");
  SetMorality(((random(1000) - 500) * (random(1000) - 500))/2);
}

void init()
{
  npc::init();
  if(!find_player(spiritMaster))
  {
    destruct(this_object());
    return;
  }

  if(CheckTarget())
  {
    if(previous_object()->GetKeyName() == CheckTarget())
    {
      message("environment", "" + previous_object()->GetKeyName() +
              " has entered " + environment(this_object())->GetShort() +
              ".", find_player(spiritMaster));
      return;
    }
  }
  message("environment", "" + previous_object()->GetKeyName() +
          " has entered " + environment(this_object())->GetShort() +
          ".", find_player(spiritMaster));
  return;
}


string CheckMaster()
{
  return(spiritMaster);
}

string SetMaster(object who)
{
  return(spiritMaster = who->GetKeyName());
}

string SetTarget(object who)
{
  return(spiritTarget = who->GetKeyName());
}

string CheckTarget()
{
  return(spiritTarget);
}

string GetShort()
{
  if(previous_object()->GetKeyName() == spiritMaster ||
     creatorp(previous_object()))
  npc::GetShort();
  else return "";
}

string CheckLong()
{
  if(previous_object()->GetKeyName() == spiritMaster ||
     creatorp(previous_object()))
  npc::GetLong();
  else return 0;
}

void StartTime(int duration)
{
  call_out("DoVanish",duration);
}

void DoVanish()
{
  message("environment","Your warding spirit has returned to it's "
          "own dimension.",find_player(spiritMaster));
  destruct(this_object());
}

