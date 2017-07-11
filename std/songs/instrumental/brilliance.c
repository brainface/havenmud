/*
 * Create Light Globe
 * A spell that creates a small ball of light
 * Created by Zaxan@Haven
 * 20th of February, 1997
 */

#include <lib.h>
#include <music.h>
#include <std.h>
inherit LIB_SONG;

static void create() {
  ::create();
	SetSong("aura of brilliance");
	SetRules("");
	SetSongType(SONG_OTHER);
  SetSkills( ([
    "instrumental music" : 35,
    ]) );
	SetMagicCost(10, 5);
	SetDifficulty(10);
	SetMorality(0);
  SetHelp(
		"This song causes a small halo of musical good cheer to form around "
		"the performer. As a side effect, this good cheer also tends to brighten "
		"the area around it."
		);
}

int eventSing(object who, int level, mixed u, object *t) {
  object halo = new(STD_SONGS "obj/bright");
  object inst = present("bard_instrument", who);
  if (!inst) return;
  level = level + who->GetSkillLevel("vocal music");
  halo->SetLife(2 * level);
  
  send_messages( ({ "play" }),
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ a brilliant melody "
    "on $target_name which brightens the area.",
    who, inst, environment(who) );
  halo->eventMove(who);
  return 1;
}
