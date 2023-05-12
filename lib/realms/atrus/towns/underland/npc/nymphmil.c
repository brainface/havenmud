// Millepede for Underland Newbies to kill
// This is literally going to be an XP bank of legs...
// This is the NewbieArea version of the Millipede mount
// Atrus@HavenMud 2023

#include <lib.h>
#include "../underland.h"
inherit LIB_NPC;


static void create() {
   npc::create();
   SetKeyName("nymph millipede");
   SetShort("a nymph millipede");
   SetId( ({ "nymph" }) );
   SetAdjectives( ({ "nymph" }) );
   SetLong("Easily the size of a small dog, this millipede nymph instills "
           "uneasy feelings as it undulates and moves. The seemingly dozens "
           "of legs and parts that make it up have little by way of form. "
           "When it is fully grown it could easily rival a horse.");
   SetRace("millipede",1);
   SetGender("male");
   SetClass("animal");
   SetLevel(1);
   
   // Ok, time to handle the limbage
   // Main "Body" for this creature
   AddLimb("first collum",0,1,({ }) );

   // Gotta have a head
   AddLimb("head","first collum",1,({ }) );

   // Add a couple feelers
   AddLimb("right feeler","head",4,({ }) );
   AddLimb("left feeler","head",4,({ }) );
   
   // Body/trunk segments

   //turns out this segment of the body doesn't have legs
   //AddLimb("first right somite","first collum",5,({ }) );
   //AddLimb("first left somite","first collum",5,({ }) );

   AddLimb("second tergum","first collum",3,({ }) );
   AddLimb("second right somite","second tergum",5,({ }) );
   AddLimb("second left somite","second tergum",5,({ }) ); 

   //most of the rest usually have 4 legs per segment til the end
   AddLimb("third tergum","second tergum",3,({ }) );
   AddLimb("third inner right right somite","third tergum",5,({ }) );
   AddLimb("third right somite","third tergum",5,({ }) );
   AddLimb("third inner left somite","third tergum",5,({ }) );
   AddLimb("third left somite","third tergum",5,({ }) );

   AddLimb("fourth tergum","third tergum",3,({ }) );
   AddLimb("fourth right somite","fourth tergum",5,({ }) );
   AddLimb("fourth left somite","fourth tergum",5,({ }) );
   AddLimb("fourth inner right somite","fourth tergum",5,({ }) );
   AddLimb("fourth inner left somite","fourth tergum",5,({ }) );

   AddLimb("fifth tergum","fourth tergum",3,({ }) );
   AddLimb("fifth right somite","fifth tergum",5,({ }) );
   AddLimb("fifth left somite","fifth tergum",5,({ }) );
   AddLimb("fifth inner right somite","fifth tergum",5,({ }) );
   AddLimb("fifth inner left somite","fifth tergum",5,({ }) );

   AddLimb("sixth tergum","fifth tergum",3,({ }) );
   AddLimb("sixth right somite","sixth tergum",5,({ }) );
   AddLimb("sixth left somite","sixth tergum",5,({ }) );
   AddLimb("sixth inner right somite","sixth tergum",5,({ }) );
   AddLimb("sixth inner left somite","sixth tergum",5,({ }) );

   AddLimb("seventh tergum","sixth tergum",3,({ }) );
   AddLimb("seventh right somite","seventh tergum",5,({ }) );
   AddLimb("seventh left somite","seventh tergum",5,({ }) );
   AddLimb("seventh inner right somite","seventh tergum",5,({ }) );
   AddLimb("seventh inner left somite","seventh tergum",5,({ }) );

   AddLimb("eighth tergum","seventh tergum",3,({ }) );
   AddLimb("eighth right somite","eighth tergum",5,({ }) );
   AddLimb("eighth left somite","eighth tergum",5,({ }) );
   AddLimb("eighth inner right somite","eighth tergum",5,({ }) );
   AddLimb("eighth inner left somite","eighth tergum",5,({ }) );

   AddLimb("ninth tergum","eighth tergum",3,({ }) );
   AddLimb("ninth right somite","ninth tergum",5,({ }) );
   AddLimb("ninth left somite","ninth tergum",5,({ }) );
   AddLimb("ninth inner right somite","ninth tergum",5,({ }) );
   AddLimb("ninth inner left somite","ninth tergum",5,({ }) );

   AddLimb("tenth tergum","ninth tergum",3,({ }) );
   AddLimb("tenth right somite","tenth tergum",5,({ }) );
   AddLimb("tenth left somite","tenth tergum",5,({ }) );
   AddLimb("tenth inner right somite","tenth tergum",5,({ }) );
   AddLimb("tenth inner left somite","tenth tergum",5,({ }) );

   AddLimb("final tergum","tenth tergum",3,({ }) );
   AddLimb("final right somite","final tergum",5,({ }) );
   AddLimb("final left somite","final tergum",5,({ }) );
   // Should be longer but for sanity and memory, I'm going to cut it off here
   // Millipedes are notorious for being >100 segments
}
