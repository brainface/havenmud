// An example NPC, prepaped by Amelia
// All lines are required unless there is a note saying it isn't.

// The next line is just a set-up that will be in ALL your code.
#include <lib.h>

// Depending on your area, it will be "averath.h" or something else.
// You don't need this line if you don't have any inventory, nor
// need to reference any other filenames.
#include "../example.h"

// Required for all NPCs.
inherit LIB_NPC;

// Next two lines open the create function and get it set up.
static void create() {
   ::create();

// The KeyName of an NPC is the one displayed during combat and
// when using emote.  It should never be capitalized unless it is 
// a proper noun, and it should
// be kept simple--almost always one word.
   SetKeyName("keyname");

// The Short description is the one displayed when a player looks
// around a room, and sees "A rabbit is here."  The Short should
// never be capitalized, unless it is a proper noun.
   SetShort("a short description");

// The Ids are all the nouns a player can refer to an NPC by.
// It's a generally good rule to always make it possible for
// the player to type "look short description" (or whatever the
// short is).  *Never ever ever* capitalize Ids, even if they
// are proper nouns.  When the mud checks for Ids, it strips all
// capitals away from what the player types.
   SetId( ({ "description","npc" }) );

// The Adjectives are all the adjectives a player can refer to an 
// NPC by, with the noun.  So while "description" doesn't fit in
// here, "short" does.  Again, never ever ever capitalize these.
   SetAdjectives( ({ "short","uninteresting" }) );

// The Long description is what shows up when a player looks at 
// the NPC.  It should never include "you", and almost never include
// "seems" (it does not "seem" like the npc has a short beard, he 
// either does or does not).  Do not describe equipment of the
// NPCs, like their spiffy axe.  These items can be taken away for
// various reasons (stealing, dismemberment, whatever).  Also,
// don't mention the position the NPC is in--behind a counter,
// standing, sitting.  This is the same description displayed while
// in a fight, AND while the NPC is first dead.  Attempt to give a
// really cohesive idea to the player of what level the NPC is, so
// that they don't try to attack something too difficult for them.
// Also, grammar applies to Longs.  
   SetLong("This is where the long description goes.  It is an "
           "uninteresting npc that is very weak.");

// Pick male or female for anything where you would expect there
// to be a gender.  So dogs, even though you would have to check,
// get a gender.  Starfish wouldn't.  Be consistent, using s/he 
// instead of it if you have a gender.  And if it's neuter, then
// be consisten and use only it/it's/etc.
   SetGender("neuter");

// You can list possible races by typing 'mraces'.  
   SetRace("human");
// A neat trick is to pick a race with the general limb structure you
// want.  Like if you are coding a wolf, pick a dog.  Then, use:
// SetRace("dog","wolf");.  The NPC has the structure of a dog,
// which is really the same as a wolf's, but when a player looks at
// it, it says 'wolf' instead of 'dog'.  You can also build an
// entire body from scratch, and you can add/remove limbs as
// desired.

// You pick whatever class you want, and put it in.  The NPC gets all
// the default skills of that class.
   SetClass("bard");

// Pick a level that matches the description.
   SetLevel(1);

// You can add in extra skills using this function.  The first number
// is how well they know it, and the second number designates whether
// the skill is primary/secondary/etc.  If you put this before
// SetLevel(), the first number (how well they know it) doesn't matter,
// because it gets reset to whatever level the npc is.
// Not required.
   SetSkill("pole attack",2,1);

// The first argument is what kind of currency, the second is how much.
// Not required.
   SetCurrency("ducats",50);

// If the NPC has an attack skill other than melee as a primary
// skill, it's a good idea to equip it.  In this case, the npc
// has pole attack, and the weapon it's wielding is a pole.
// The first argument given is always the filename.  The second i
// either a command for the NPC to input (wield weapon, put item 
// in bag) OR a number.  It's nice to provide a reward for killing
// something, be it cash or some sort of weapon/armour/treasure
// type thing.  Not required.
   SetInventory( ([
                    EXAMPLE_OBJ + "weapon" : "wield weapon",
                    EXAMPLE_OBJ + "armour" : "wear armour",
                    EXAMPLE_OBJ + "treasure" : 2,
               ]) );

// If your npc is a bard, might be a good idea to teach it some songs.
// Looks at 'help song_reqs' to see what songs it can learn.
// Be sure the npc has the requirements!  Notice, that this NPC can
// learn shielding song and debutant aria, but can't learn ballad of
// autumn--so when the npc tries to sing it, it won't work.  The
// first argument given is the song name, the second is the %
// experience.  If npc is a mage, use SetSpellBook().  It works
// exactly the same way.  Check "help spell_reqs" for a spell list.
// Not required.
   SetSongBook( ([
                   "shielding song" : 5,
                   "debutant aria" : 3,
                   "ballad of autumn" : 100,
              ]) );

// Actions.  Yuck.  This is one way to annoy a player.
// The first argument is the % chance of the npc performing one of
// actions every heartbeat.  The second is all the different 
// things the npc might do.  This function is not required, and
// if you choose to use it, try to have a variety of actions.  This
// is very useful for npcs that do things--like an npc that gives
// things out to newbies, or is trying to sell rat-on-a-sticks.
// Actions are also useful for casting spells.  The ! at the
// begining of an action means that the npc performs it, just as
// if a player typed it.  When there isn't a !, it merely gets
// displayed to everyone in the room.
   SetAction(1, ({ "!emote whines.","!emote sniffles.","The npc "
                   "kicks a bucket.","!sing shielding song" }) );

// SetCombatAction() functions is just the same way as SetAction(),
// except the actions are used during combat.  This is how you
// can set it up to sing songs or cast spells.  It can also be
// used to set up special attacks.  This is not a required function.
   SetCombatAction(5, ({ "!emote growls.","!sing debutant aria" }) );

// Positive morality means it's good, and killing it will make the 
// player evil.  Negative means evil.  A morality of 50 is just a
// kinda-leans-towards-good type morality, while 2000 would be 
// saintly.  Some things don't have a morality (like a squirrel)
// but anything that might have one, should.  This way people can
// get saintly/demonic and have it match what they actual kill.
   SetMorality(50);

// Don't forget this line.  It makes everything buggy when you do.
}
