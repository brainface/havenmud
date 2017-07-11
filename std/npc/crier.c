#include <lib.h>
inherit LIB_SENTIENT;

static void create()
{
	sentient::create();
	SetKeyName("recruiter");
	SetShort("Recruiter for the Grymxorian Army");
	SetId(  ({
		"recruiter",
		"nosferatu",
		})  );
	if(random(10) > 4)  {
		SetGender("male");
	} else {
		SetGender("female");
	}
	SetRace("nosferatu");
	SetClass("cavalier");
	SetLevel(random(5) + 8);
	SetWander(25);
	SetLong("This recruiter is wearing the regalia of the Grymxorian "
		"Army.  The recruiter wanders about Kailie spreading the "
		"news about the army gathering in the Estergrym mountains.  "
		"Given time the recruiter could tell one about all the "
		"benefits of army life.  ");
	SetAction(10, ({
		"!shout Join the Grymxorian Army!",
		"!shout Looking for Excitement and Adventure?  Then join "
		"the Grymxorian army",
		"!shout Spoils and Plunder for every member of the Grymxorian "
		"Army!",
		"!shout Be a part of the winning team and Join the Grymxorian "
		"Army!",
		"!shout This isn't your father's army!",
		"!shout Quick promotion and leadership opportunites available "
		"in the Grymxorian Army!",
		"!shout Join today before your town is sacked!",
		"!shout Weapon training available to all members of the "
		"Grymxorian Army!",
		"!shout Learn to be a soldier!",
		})  );
	SetInventory(  ([
		"/domains/grymxoria/obj/nosf_lance" :
			"wield lance",
		"/domains/grymxoria/obj/nosf_armor" :
			"wear armor",
		"/domains/grymxoria/obj/blood_sword" :
			"wield sword",
		"/domains/grymxoria/obj/wall_shield" :
			"wear shield on left arm",
		])  );
}


/* Approved by Arathorn on Thu Feb 26 20:07:37 1998. */
