#include <lib.h>                   

// mikes includes dir
#include "../haven.h" 

// must be in all rooms
inherit LIB_ROOM;      

static void create() {
// get it started   
room::create();     

SetClimate("indoors");
SetAmbientLight(30);
SetShort("a small alcove");           
SetLong(
"This alcove sits apart from the main body of the temple, separated from the "
"open room to the north by wooden dividers. Herbs dangle from strings in the "
"ceiling, and stacks of vials and decanters hang on a wooden shelf along the "
"outside wall. In the center of the room stands a cluttered workbench."                                     
);                                                                                

SetItems( ([
({"alcove"}) :
(: GetLong :),        
({"ceiling","rays","marble"}) :          
"Rays of light dance along the marble ceiling. ",
({"temple","body"}) :
"The open floor of the Eclat temple lays to the north.",
({"dividers"}) :
"Ornate dividers made of dark maple obscure the way to the north, "
"without impeding movement.",
({"herbs","strings"}) :
"A variety of herbs of varying states of pungeance dangle from the "
"ceiling.",
({"stacks","vials","decanters","shelves","shelf","equipment"}) :
"Specialized alchemical equipment, useless to anyone but a herbalist, "
"is sorted haphazardly along the shelf.",
({"workbench","bowls","flasks","mixtures"}) :
"The workbench is cluttered with half-empty bowls and flasks, filled "
"with incomplete mixtures.",
({"floor","marble"}) :
"Some overworked janitor has kept the marble here as spotless as in the "
"main temple."
]) );                                                                        

SetItemAdjectives( ([
"temple" : ({"eclat","Eclat"}),
"dividers" : ({"wooden","ornate"}),
"stacks" : ({"alchemical",}),
"workbench" : ({"cluttered","half-empty","incomplete"}),
]) );

SetListen( ([
"default" : "Something pops murkily on the workbench.",
]) );

SetSmell( ([
"default" : "The building smells worse than a parvan crossroads.",
"herbs" : "Your feel your eyes tear as your nose goes temporarily numb.",
]) );

SetInventory( ([
H_NPC + "apothecary" : 1,
]) );

SetExits( ([
"north" : H_ROOM "church/eclat_temple.c",
]) );
}

