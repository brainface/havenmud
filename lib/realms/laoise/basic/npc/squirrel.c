#include <lib.h>  // Needs to be included in all files

inherit LIB_NPC;
/* Sets the file type, which gives this file access to
 * all of the functions defined in the npc lib.
 */

static void create() {
  npc::create();
/* These two lines start the file. Note it's npc here, instead of room */

  SetKeyName("squirrel");
/* Key names are used for npcs and objs and allow them to
 * interact with things like the combat daemon. Set Key name should
 * be one or two words, but unique and descriptive. So, if there
 * are 9 bees, the one queen bee should have "queen bee" as
 * her set key name, so players will see "Queen been slashes
 * you viciously" while in combat and know which they're fighting.
 */

  SetId( ({ "squirrel", "rodent" }) );
/* This sets the "names" for the npc that players can use to 
 * interact with it. e.g. they can <look squirrel>
 */

  SetAdjectives( ({ "small", "brown" }) );
/* This works like SetItemAdjectives does in a room, by setting
 * adjectives that can modify the nouns set in the Id section.
 * e.g. players can <look small squirrel> or <look brown squirrel> 
 */

  SetShort("a small brown squirrel");
/* This is what players will see when they walk into a room or
 * look. The first letter should _not_ be capitalized, except
 * when it is the proper name of the npc (e.g. Maur the dragon)
 * Normally the short starts with an article, such as "a"
 * as in "a goden fisherman", "a haventown peasant".
 */

  SetLong(
    "This is a small furry brown squirrel. He has a bushy "
    "brown tail which sticks up behind him and wiggles when "
    "he moves. This squirrel looks small and weak. Go south "
    "from here to see an npc example without commented code."
  );
/* This is the description that players will see when they
 * look at an npc. It should be 2-3 lines of good description
 * (unlike this example), and should include a reference to
 * how strong this animal would be in combat. e.g. "This giantic
 * lizardman looks as if he would be a very formitable opponent."
 */

  SetRace("rodent");
/* This determines the body configuration of the npc, specifically
 * its limb structure and stats. Valid races are listed by using
 * the <mraces> command. Npcs MUST have a race specified.
 */

  SetClass("animal");
/* This determines the skill set that an npc has. For most npcs
 * "animal" is appropriate, unless there's a specific reason for
 * a different class, such as the npc being a city guard.
 */ 

  SetLevel(1);
/* When combined with the set race and set class this determines
 * the actual skill and stat values that the npc will have
 */

  SetGender("male");
/* Valid choices are male, female or neuter. */

  SetAction(10, ({
    "The squirrel looks around for a tree to climb.",
    "!cackle",
  }) );
/* SetAction gives an npc a percent chance of performing
 * one of the listed actions each heartbeat. In this case
 * the squirrel has a 1 percent chance each heartbeat of
 * performing one of the actions listed. ! will force the
 * npc to do the argument, in this case to cackle.
 */

/* The next two functions are not required, but can be
 * used to create more interesting areas and npcs.
 */
  SetCombatAction(1, ({
    "The squirrel LUNGES foward at you.",
    "The squirrel attempts to gnaw on you!",
  }) );
/* These are similar to SetActions, but are only called when
 * the npc is in combat. This would be where you'd have an npc
 * cast spells, if appropriate.
 */

}
