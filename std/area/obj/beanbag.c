/* Created by Zeratul@Haven
 * Good example of the jump verb
 */
#include <lib.h>
#include <jump.h>
#include "../area.h"
inherit LIB_ITEM;
inherit LIB_JUMP;

int DoBounce();

static void create() {
  item::create();
  SetKeyName("inflatable beanbag");
  SetId( ({ "beanbag", "bag" }) );
  SetAdjectives( ({ "inflatable", "bean" }) );
  SetShort("an inflatable beanbag");
  SetLong(
     "This is a inflatable beanbag. For that 'special' kind of person"
     "(we all know its you Kalida)."
  );
  SetPreventGet("Whoa there sailor, you cannot get that.");
  SetMass(1);
  SetJump( (: DoBounce :), JUMP_ON);
}

int DoBounce() {
  if(!creatorp(this_player())) {
    message("system","Sorry, immortal fun only!",
    this_player());
    return 0;
  }
  else
  {
    send_messages( ({ "jump" }), "$agent_name $agent_verb "
    "up and down on the inflatable beanbag excitedly!",
    this_player(), 0, environment(this_player()));
    this_player()->eventForce("whee");
    return 1;
    }
 }
