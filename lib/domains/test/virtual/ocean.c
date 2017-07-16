#include <lib.h>
#include <std.h>
#include <domains.h>
#include <daemons.h>
#define  OCEAN  "/domains/zalbar/virtual/ocean/"
//#define OCEAN  INNERSEA_VIRTUAL "ocean/"
inherit LIB_FISHING;

int X, Y, counter;

void createShipEncounter(int x, int y);

static void create(int x, int y) {
  string n, s, e, w, ne, nw, se, sw;
  string long = "", short = "", smell = "", listen = "", climate = "";
  ::create();
  counter = 0;
  X = x;
  Y = y;
  SetProperty("ocean", 1);
  n  = OCEAN + (x) + "," + (y + 1);
  s  = OCEAN + (x) + "," + (y - 1); 
  e  = OCEAN + (x + 1) + "," + (y);
  w  = OCEAN + (x - 1) + "," + (y);
  ne = OCEAN + (x + 1) + "," + (y + 1);
  se = OCEAN + (x + 1) + "," + (y - 1);
  nw = OCEAN + (x - 1) + "," + (y + 1);
  sw = OCEAN + (x - 1) + "," + (y - 1);
  SetSpeed(5);
  SetMaxFishing(5);
  SetChance(10);
  SetFish( ([
    DIR_STD "fish/guppy" : 60,
    DIR_STD "fish/blackfin_tuna" :  40,
    DIR_STD "fish/bonnethead" :  30,
    DIR_STD "fish/mackerel" :  45,
    DIR_STD "fish/mako" :  25,
    DIR_STD "fish/marlin" :  20,
    DIR_STD "fish/seabass" :  50,
    DIR_STD "fish/shark" :  40,
    DIR_STD "fish/swordfish" :  20,
    DIR_STD "fish/yellowtail" :  25,
    DIR_STD "fish/trout" :  50,
    ]) );
   SetDomain("Innersea");
    
  /* Basic Long Setup.  Defines Which ocean we're in */
  if (x > -80 && x < 55 && y < 51 && y > -50) {
    short = "the Ruined Sea";
    long = "The reddish waters of the Ruined Sea swirl around in chaotic fury, "
           "their motion that of waves on a mission. ";
    smell = "The air has a faint coppery smell.";
    listen = "The air is quiet with few birds even chirping.";       
    }
  if (y >= 51) {
    short = "the Northern Sea";
    long  = "The frigidly cold waters of the Northern Sea creak their waves "
            "across the area. Small mounds of ice bob up and down in the "
            "cold, chill waters. ";  
    climate = "arctic";
    smell = "The air has a chilled quality from icy flows and winds.";
    listen = "The crash of waves on ice and icebergs breaking up is loud.";
    }
  if (y <= -50) {
    short = "the Southern Sea";
    long  = "The warm, peaceful waters of the Southern Sea gently ripple "
            "into swirls of small currents. Light glistens off the waves "
            "in a reassuring manner. ";
    climate = "sub-tropical";
    smell = "A breeze of fresh air is carried from afar.";
    listen = "The soft ripple of the currents is quiet and friendly.";
   }
  if (x <= -80 || x >= 55) {
    short = "the Endless Sea";
    long  = "The waves of the Endless sea stretch out in all directions as "
            "far as the eye can sea. Clouds don't seem to make any impression "
            "on the water, and the sky seems lonely and forelorn. ";
    smell = "The air is breezy, but surprisingly devoid of smell.";
    listen = "The ocean is quiet and calm.";        
    }
 
  /* Voodoo mysticism for some exits.  Kids, don't try this at home. */
  
  if (y < 100 && y > 0 && x < 4 && x > -70)  
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (y < 92 && y > 0 && x < -90 && x > -155)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (x >= -90 && x < -87 && y > 6 && y < 100)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (x > -87 && x <=- 70 && y > 3 && y < 100)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (y >= 92 && y > 115 && x < -55 && x > -150)
  		 ne = se = nw = n = sw = s = e = w = 0; 
  if (y < 100 && y > 50 && x >= 4 && x < 55)
  	 	ne = se = nw = n = sw = s = e = w = 0;  
    /* Area is entirely within the island.  
     * If you're here, you're fucked. 
     */
  
  
  /* South Coast */
  
  if (y == 0 && x >= -25 && x <= 3) {
  	if (x != 3) ne = 0;
  	if (x != -12) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  	if (x !=  -13) n = 0;
  	if (x <= -12 && x > -14) {
  		long += " A small cove can be seen north of here. ";
  	}
  }        
  
  
  /* Mark off the Penninsula - East Coast */
  if (x == -26 && y == -12) {
  	nw = 0; 
  	long += " The Ruined Sea washes against the Peninsula here, "
  	        "and off to the northwest the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  if (x == -26 && y <= 0 && y >= -11) {
  	nw = w = 0;
  	if (y != -11) sw = 0;
  	if (y == 0) n = ne = 0;
    if (y <= -4)
    	long += " The Ruined Sea washes against the Peninsula here, "
  	          "and off to the west the city of Sanctum can be seen.";
  	  else
  	  	long += " The Ruined Sea washes against the Peninsula here. ";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  
  /* Mark off the Peninsula - South Coast */
  if (x >= -38 && x <= -27 && y == -12) {
  	n = 0;
  	if (x != -38) nw = 0;
  	if (x != -27) ne = 0;
        long += " The Ruined Sea washes against the Peninsula here, "
  	        "and off to the north the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  
  /* Mark off the Penninsula - West Coast */
  if (x == -39 && y == -12) {
  	ne = 0; 
  	long += " The Ruined Sea washes against the Peninsula here, "
  	        "and off to the northeast the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }
  if (x == -39 && y < -4 && y >= -11) {
  	e = ne = 0;
  	if (y != -11) se = 0;
    long += " The Ruined Sea washes against the Peninsula here, "
            "and off to the east the city of Sanctum can be seen.";
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  }      
  
  
  
  /* After Peninsula - Rest of Southern Coast to Crystal Reaches */
  if (x < -38 && x >= -50 && y == -4) {
  	n = ne = 0;
  	if (x == -39) e = se = 0;
  	if (x != -50) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  /* So players cannot sail into or behind land */
  if ((x == -51 && y == -4) || (x == -52 && y == -3) ||
  	  (x == -70 && y == -2) || (x == -71 && y == -1) ||
  	  (x == -86 && y == 2) || (x == -87 && y == 3) ||
  	  (x == -101 && y == -2) || (x == -102 && y == -1)) {
  	ne = 0;
   }
  
  
  if ((x == -51 && y == -3) || (x == -70 && y == -1) ||
  	  (x == -86 && y == 3) || (x == -101 && y == -1)) {
  	ne  = n = e = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  if (x <= -52 && x >= -69 && y == -2) {
  	ne = n = 0; 	
  	if (x == -52) e = 0;
  	if (x != -69) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  if (x == -71 && y >= 0 && y <= 2) {
  	e = ne = 0; 	
  	if (y != 0) se = 0;
  	if (y == 2) n = nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  /* Lloryk Road Area*/
  if (x < -71 && x >= -85 && y == 2) {
  	ne = n = 0; 		
  	if (x != -85) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  
  if (x == -87 && y >= 4 && y <= 6) {
  	e = ne = 0; 	
  	if (y != 4) se = 0;
  	if (y == 6) n = nw = 0;
  	
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  if (x == -88 && y == 6) {
  	nw = ne = 0;
    SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }
  if (x == -89 && y == 6) {
  	nw = w = ne = n = 0;
    SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	
  if ((x == -89 && y == 5) || (x == -90 && y == -1) ||
  	  (x == -91 && y == -2)) nw = 0;    
    	
  if (x == -90 && y <= 5 && y >= 0) {
  	w = nw = 0;
  	if (y == 5) n = 0;
  	if (y != 0) sw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	
  if (x == -91 && y == -1) {
  	n = nw = w = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	

  /* Around Gwonish Coast */
  if (x <= -92 && x >= -97 && y == -2) {
  	n = 0;
  	if (x != -92) ne = 0;
  	if (x != -97) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  }	
  if (x == -98 && y >= -2 && y < 0) {
  	if (y == -2) ne = 0;
  	if (y == -1) {
  		SetProperty("shallows", 1);
  		RemoveProperty("ocean");
  		long += " The sea ends here along the southern shore of "
  	        "Kailie's northern continent. ";
  	  e = ne = 0;
  		}
  	}
  if (y == 0 && x <= -98 & x >= -155) {
  	n = ne = 0;
  	if (x == -98) e = 0;
  	if (x != -155) nw = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southern shore of "
  	        "Kaiie's northern continent. ";
  }
  if (x == -156 && y == 0) {
  	ne = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the southwestern shore of "
  	        "Kailie's northern continent. ";
  } 

  /* East Coast */
  
  if (x > 3 && x <= 6 && y >= 0 && y < 4) {
    int delta = (x - 3);
    if (y - delta >= -1) {
    	nw = 0;
    	if (y - delta >= 0) {
    		if ((x != 6 ) && (y != 3)) n = 0;
    		w = 0;
  			SetProperty("shallows", 1);
  			RemoveProperty("ocean");
  			long += " The sea ends here at the southeastern shore of "
  	    		    "Kailie's northern continent. ";
  			}
  		}
  	} 
  		  
  if (x == 6 && y >= 4 && y < 33) {
    w = nw = sw = 0;
    SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	if (y >= 10) {
  		long += " The Ruined Sea washes against the HavenWood here, "
  	        "and off to the west nothing but trees can be seen.";
    }
  	else { long += " The sea ends here at the eastern shore of "
  	        "Kailie's northern continent. ";
  	}
  }   
   
  /* Mark off the HavenWood */
  if (y == 33 && x >= 6 && x <= 10) {
  	nw = n = 0;
    if (x != 10) ne = 0;
    if (x == 6) w = 0;
    long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the north.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  
  if ((x == 11 && y == 33) || (x == 12 && y == 34)) {
  	nw = 0;
  	long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the northwest.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  if (x == 11 && y == 34) {
  	n = nw = 0;
  	long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the north and west.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  if (x == 12 && y >= 35 && y < 38) {
  	w = nw = 0;
  	if (y != 35) sw = 0;
  	long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the west.";
    SetProperty("shallows", 1);
    RemoveProperty("ocean");
  }
  
  if (y == 38 && x >= 12 && x < 25) {
  	n = nw = 0;
  	if (x == 12) sw = 0;
  	if (x != 24) ne = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	if (x != 12) {
  		long += " The Ruined Sea washes against the HavenWood here, "
  	          "and off to the north nothing but trees can be seen.";
  	  }
  		else {
  			long += " The Ruined Sea runs up and laps against the "
            "smooth and sandy beach to the west and nothing but "
            "trees can be seen to the north.";
      	}
  }  		
  
  /* Curve upward towards Parva (NE) and not letting anything get behind */  
  if (x >= 25 && y >= 38 && x <= 30 && y <= 44) {
  	int delta = (x - 25);
    if ((y - 39) - delta >= -1) {
    	nw = 0;
     	if ((y - 39) - delta >= 0){
    		w = 0;
    		if (x != 30 && y != 44) {
    			n = 0;
    			SetProperty("shallows", 1);
      		RemoveProperty("ocean");
    		  long += " The Ruined Sea runs up and laps the coast here, but to the "
                "north and west nothing can be seen but trees and dark woods.";
        }
        else {
        	SetProperty("shallows", 1);
      		RemoveProperty("ocean");
        	long += " The Ruined Sea runs up and laps the coast here, but to the "
                "west nothing can be seen but trees and dark woods."; 
        }
  		}
 		}
 	}
  /* End of curving */

  /* Parvan Coast */  		
 	if (x == 30 &&  y > 44 && y <= 50) {
  		w = nw = sw = 0;
  		SetProperty("shallows", 1);
      RemoveProperty("ocean");
  		if (y <= 47) {
  			long += " The Ruined Sea runs up and laps the coast here, battering "
      	   			"the port of Parva to the west.";
      	   		}
      	else if (y == 50) {
      		n = ne = 0;
      		long += " The Ruined Sea runs up and laps the coast here, but to "
      						"the north and west nothing can be seen but trees and "
      						"dark woods.";
      		}
      		else {
      			long += " The Ruined Sea runs up and laps the coast here, but to "
      			  			"the west nothing can be seen but trees and dark woods.";
      			}
      	}
    
    if (x > 30 &&  x < 55 && y == 50) {
    	n = nw = 0;
    	if (x != 54) ne = 0;
    	SetProperty("shallows", 1);
      RemoveProperty("ocean");
    	long += " The sea crashes up against the shore battering the Estergrym Mountains "
    	        "that are to the north. ";
   	}
		if (x == 55 && y == 50) {
			nw = 0;
			SetProperty("shallows", 1);
      RemoveProperty("ocean");
			long += " The sea crashes up against the shore battering the Estergrym Mountains "
    	        "that are to the northwest. ";
   	} 
    if (x == 55 && y > 50 && y < 100) {
    	if (y != 51) sw = 0;
    	nw = w = 0;
    	SetProperty("shallows", 1);
      RemoveProperty("ocean");
    	long += " The sea crashes up against the shore battering the Estergrym Mountains "
    	        "that are to the west. ";
   	} 
   	
  /* North Coast */
  if (x <= 55 && x >= -30 && y == 100) {
  	if (x != 55) s = 0;
    sw = se = 0;
    if (x == -30) w = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The sea ends here along the northern shore of "
  	        "Kailie's northern continent. ";
  	}        
  		
  /* Slowly curve to northwest */
   if (x <= -30 && x >= -43 && y > 100 && y <= 113) {
      int delta = (x + 30);
      if ((y - 101) + delta <= 0) {
      	if (x != -43 && y != 113) sw = 0;
      	if (x == -42 && y == 113) sw = 0;
      	if ((y - 101) + delta <= -1) {
      	  s = 0;
          if (x != -43 && y != 113) w = 0;
          SetProperty("shallows", 1);
          RemoveProperty("ocean");
          long += " The shore curves from northwest to southeast here, and "
                  "small beaches and bays line the waterfront.";
        }
      }
    }  
  /* End Curve */
      
 	/* Curve downward to southwest */ 
  if (x < -43 && y <= 113 && x > -48 && y >= 109) {
  	int delta = (-43 - x);
  	if (delta + (y - 113) <= 1) {
  		se = 0;

     	if ((y - 113) + delta <= 0){
      		s = e = 0;
      		SetProperty("shallows", 1);
     	    RemoveProperty("ocean");
      		long += " The shore curves from northeast to southwest here, and "
                  "small beaches and bays line the waterfront.";
      }
    }
    if (x == -47 && y == 109) sw = 0;
  }
  /* End Curve */
      
 /* Curve upward to Gurov (NW) */ 
  if ( x <= -48 && y >= 109 && x > -54 && y <= 115) {
	    int delta = (x + 48);
      if (x == -48 && y == 109) se = 0;
      if ((y - 109) + delta <= 1) {
      	sw = 0;
      	if ((y - 109) + delta <= 0) {
      		SetProperty("shallows", 1);
        	RemoveProperty("ocean");
          s = w = 0;
          long += " The shore curves from northwest to southeast here, and "
                  "small beaches and bays line the waterfront.";
        }
      }
    }  
  /* End Curve */	
   
  if (x <= -54 && x >= -154 && y == 115) {
  	s = 0;
  	if (x != -154) sw = 0;
  	if (x != -54) se = 0;
  	SetProperty("shallows", 1);
  	RemoveProperty("ocean");
  	long += " The water crashes against the northern shore of the continent "
              "here, leaving icy beaches and cold water along the coast.";
  	}
  		   
  /* West Coast */
  if (x == -155 && y == 115)se = 0; 

  if (x == -155 && y <= 114 && y >= 97) {
    	e = 0;
    	if (y != 114) ne = 0;
    	if (y != 97)  se = 0;
  		SetProperty("shallows", 1);
  		RemoveProperty("ocean");
  		long += " The sea ends here at the western shore of "
  	  	      "Kailie's northern continent. ";
  	} 
  
  /* Around Keryth */
  if (y == 96 && x >= -155 && x <= -154) {
  	ne = 0;
  	if (x == -154) {
  		n = e = 0;
  		SetProperty("shallows", 1);
    	RemoveProperty("ocean");
    	long += " The sea ends here at the western shore of "
  		  		  "Kailie's northern continent. ";
  		}
  	}
  if (y == 95 && x >= -154 && x <= -153) {
		ne = 0;
		if (x == -153) {
			n = e = 0;
  		SetProperty("shallows", 1);
    	RemoveProperty("ocean");
    	long += " The sea ends here at the western shore of "
  		  		  "Kailie's northern continent. ";
  		}
  	}
  	
  if (y == 94 && x >= -155 && x <= -152) {
  	if (x == -152) n = ne = e = se = sw = 0;
  	if (x == -153) ne = sw = se = 0;
  	if (x == -154) s = 0;
  	if (x == -155) se = 0;
  	SetProperty("shallows", 1);
    RemoveProperty("ocean");
    long += " The sea ends here at the western shore of "
  	  		  "Kailie's northern continent. ";
  	} 
  if (x == -153 && y == 93) se = s = sw = w = 0; 
  	
	if (x == -155 && y < 94 && y > 89) {
		e = se = 0;
		if (y != 93) ne = 0;
		SetProperty("shallows", 1);
    RemoveProperty("ocean");
    long += " The sea ends here at the western shore of "
  				  "Kailie's northern continent. ";
  	}
  
  if (x <= -155 && x >= -165 && y == 89) {
  	se = 0;
  	if (x != -165) s = sw = 0;
  	if (x == -155) ne = e = 0;	
  	SetProperty("shallows", 1);
    RemoveProperty("ocean"); 
    long += " The sea ends here at the western shore of "
  	    		    "Kailie's northern continent battering "
  	    		    "the mountains of the FrostMarches. ";
  }
  
  if (x == -165 && y < 89 && y >= 57) {
  	e = ne = 0;
  	if (y != 57) se = 0;
  	SetProperty("shallows", 1);
    RemoveProperty("ocean"); 
    long += " The sea ends here at the western shore of "
  	    		    "Kailie's northern continent. ";
  }
  
  /* Curve downward to the southeast and not letting anything get behind */  
  if (x >= -165 && y < 57 && x < -156 && y >= 48) {
  	int delta = (-165 - x);
    if ((y - 57) - delta >= -1) {
    	ne = 0;
    	if ((y - 57) - delta >= 0){
    		e = n = 0;
    		if (x == -156 && y == 48) se = 0;
    		SetProperty("shallows", 1);
        RemoveProperty("ocean");
      	long += " The sea ends here at the western shore of "
  	    		    "Kailie's northern continent. ";
  	  }
  	}
  }
  /* End of curving */
  
 if (x == -156 && y <= 48 && y >= 1) {
  	e = ne = 0;	
  	if (y == 48) n = 0;
  	if (y != 1) se = 0;
  	SetProperty("shallows", 1);
    RemoveProperty("ocean");
  	long += " The sea ends here at the western shore of "
  	    		    "Kailie's northern continent. ";	
 }
  	
  /* Shallows */
  
  if (x >= -170 && x <= 35 && y >= -10 && y <= 120) {
  	if (GetProperty("ocean")) {
  		RemoveProperty("ocean");
  		SetProperty("shallows", 1);
  		long += " The water is a deep green here so close to land.  While "
  		        "deep enough to drown in, the water isn't too far from land.";
    }
  }
/* Tai-Ri */
  
  if (x >= 80 && x <= 220 && y <= -30 && y >= -160) {
  	if (GetProperty("ocean")) {
  		RemoveProperty("ocean");
  		SetProperty("shallows", 1);
  		SetDomain("Tairi"); 		
  		long += " Near the far eastern lands of Tairi, the water is a deep green.  Too "
  		        "deep for wading yet not so far from land to require an ocean "
  		        "vessel, the shallows make for excellent sport.";
  		}
   }
  if (x <= 185 && x >= 115 && y <= -50 && y >= -140) {
  	if (x ==  185) {
  		if (y < -50) nw = 0;
  	  if (y > -140) sw = 0;
  	  if (y != -140 && y != -50) { 
  	  	w = 0;
  		  long += " To the west lie the lands of Tairi.";
  		  }
  	}
  	if (x == 185 && y == -50) {
  		sw = 0;
  		long += " To the southwest lie the lands of Tairi.";
  	}	
  	if (x == 115 && y == -50) {
  		se = 0;
  		long += " To the southeast lie the lands of Tairi.";
  	}  	
  	if (x == 185 && y == -140) {
  		nw = 0;
  		long += " To the northwest lie the lands of Tairi.";
  	}
  	if (x == 115 && y == -140) {
      ne = 0;
  		long += " To the northeast lie the lands of Tairi.";
  	}
  	if (x == 115) {
  		if (y < -50) ne = 0; 
  	  if (y > -140) se = 0; 
  		if (y != -50 && y != -140) {
  			e = 0;
  			long += " To the east lie the lands of Tairi.";
  		}
  	}
  	if (y == -50) {
  		if (x < 185) se = 0;
  	  if (x > 115) sw = 0;
  		if (x != 115 && x != 185) { 
  		  s = 0;
  		  long += " To the south lie the lands of Tairi.";
  		}
  	}
  	if (y == -140) {
  		if (x < 185) ne = 0;
  	  if (x > 115) nw = 0;
  		if (x != 115 && x != 185) {
  			n = 0;
  		  long += " To the north lie the lands of Tairi.";
  		}
  	}
  }
/* Averath */

  if (x >= -15 && x <= 15 && y <= -90 && y >= -115) {
  	if (GetProperty("ocean")) {
  		RemoveProperty("ocean");
  		SetProperty("shallows", 1);
  		SetDomain("Averath");
  		long += " Near the Island of Averath, the water is a deep green.  Too "
  		        "deep for wading yet not so far from land to require an ocean "
  		        "vessel, the shallows make for excellent sport.";
  		}
   }
  if (x <= 10 && x >= -10 && y <= -100 && y >= -110) {
  	if (x ==  10) {
  		if (y < -100) nw = 0;
  	  if (y > -110) sw = 0;
  	  if (y != -110 && y != -100) { 
  	  	w = 0;
  		  long += " To the west lies Averath Island.";
  		  }
  	}
  	if (x == 10 && y == -100) {
  		sw = 0;
  		long += " To the southwest lies Averath Island.";
  	}	
  	if (x == -10 && y == -100) {
  		se = 0;
  		long += " To the southeast lies Averath Island.";
  	}  	
  	if (x == 10 && y == -110) {
  		nw = 0;
  		long += " To the northwest lies Averath Island.";
  	}
  	
  	if (x == -10 && y == -110) {
      ne = 0;
  		long += " To the northeast lies Averath Island.";
  	}
  	if (x == -10) {
  		if (y < -100) ne = 0; 
  	  if (y > -110) se = 0; 
  		if (y != -100 && y != -110) {
  			e = 0;
  			long += " To the east lies Averath Island.";
  		}
  	}
  	if (y == -100) {
  		if (x < 10) se = 0;
  	  if (x > -10) sw = 0;
  		if (x != 10 && x != -10) { 
  		  s = 0;
  		  long += " To the south lies Averath Island.";
  		}
  	}
  	if (y == -110) {
  		if (x < 10) ne = 0;
  	  if (x > -10) nw = 0;
  		if (x != 10 && x != -10) {
  			n = 0;
  		  long += " To the north lies Averath Island.";
  		}
  	}
  }

   
/* Specific Connections */

  if (x == -13 && y == 1) {
  	s  = OCEAN + -13 + "," + 0;
  	se = OCEAN + -12 + "," + 0;
  	ne = SOUTHERN_COAST_AREAS "acove/rooms/cove3";
  	SetProperty("shallow", 1);
  	RemoveProperty("ocean");
  	long = "The sea ends here along a sandy white beach. A beached ship "
  	        "sits behind some sand dunes to the east. ";
  }
  if (x == -21 && y == 0) {
  	n = SOUTHERN_COAST_AREAS "meadow/rooms/meadow11";
  	long += " Directly to the north is Platypus Bay.";
  	}
  if (x == -20 && y == 0) {
  	n = SOUTHERN_COAST_AREAS "meadow/rooms/meadow12";
  	long += " Directly to the north is Platypus Bay.";
  	}
  if (x == -19 && y == 0) {
  	n = SOUTHERN_COAST_AREAS "meadow/rooms/meadow13";
  	long += " Directly to the north is Platypus Bay.";
  	}
  if (x == 0 && y == -100) {
  	s = AVERATH_TOWNS "averath/room/wharf";
  	long += " Directly to the south is the Wharf at Averath.";
  	}
  if (x == -26 && y == -7) {
     w = PENINSULA_TOWNS "sanctum/room/rd05";
     }
  if (x == -32 && y == -12) {
     n = PENINSULA_TOWNS "sanctum/room/docks";
     long += " The docks of Sanctum lies to the north. ";
     }	
  if (x == 0 && y == 0) {
     n = SOUTHERN_COAST_TOWNS "haven/room/wharf";
     long = " The Ruined Sea stretches out to the horizon. To the north lies "
            "Haven Town. ";
     }
  if (x == 30 && y == 46) {
     w = HAVENWOOD_TOWNS "parva/room/docks1";
     long += " Directly to the west lie the Parva docks.";
     }
  if (x == 9 && y == 33) {
  	 n = HAVENWOOD_AREAS "wood/rooms/beach10";
  	}
  if (x == 10 && y == 33) {
  	 n = HAVENWOOD_AREAS "wood/rooms/beach11";
  	}
  if (x == 11 && y == 33) {
  	 nw = HAVENWOOD_AREAS "wood/rooms/beach11";
  	}
  if (x == 11 && y == 34) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach11";
  	 n = HAVENWOOD_AREAS "wood/rooms/beach12";
  	}
  if (x == 12 && y == 34) {
  	 nw = HAVENWOOD_AREAS "wood/rooms/beach12";
  	}	
  if (x == 12 && y == 35) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach12";
  	}
  if (x == 12 && y == 36) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach13";
  	}
  if (x == 12 && y == 37) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach14";
  	}
  if (x == 12 && y == 38) {
  	 w = HAVENWOOD_AREAS "wood/rooms/beach15";
  	}
  if (x == 150 && y == -50) {
     s = TAIRI_TOWNS "tairi/room/path11";
     long += " The village of Tairi lies to the south.";
     } 
  if (x == -88 && y == 6) {
  	 n = CRYSTAL_REACHES_TOWNS "lloryk/room/wharf";
  	 long += " The Shire lies to the north.";
  	 }
  if (x == -49 && y == 110) {
     w = GUROV_TOWNS "gurov/room/bay5";
     s = GUROV_TOWNS "gurov/room/bay7";
     long += " The Gurov Bay lies to the south and west.";
     }
  if (x == -50 && y == 111) {
     w = GUROV_TOWNS "gurov/room/bay3";
     s = GUROV_TOWNS "gurov/room/bay5";
     long += " The Gurov Bay lies to the south and west.";
     }
  if (x == -51 && y == 112) {
     s = GUROV_TOWNS "gurov/room/bay3";
     long += " The Gurov Bay lies to the south.";
     }
  if (x == -68 && y == -2) {
     n = CRYSTAL_REACHES_TOWNS "karak/room/rd7";
     long += " To the north lies the Orcish city of Karak.";
     }
  if (x == -97 && y == -2) {
     n = CRYSTAL_REACHES_AREAS "gwonish/room/swamp25";
     long += " To the north lies a few boulders.";
     }
  if (x == -93 && y == -2) {
     n = CRYSTAL_REACHES_TOWNS "gwonish/room/gw01";
     long += " To the north lies the Lizardman village of the Gwonish Swamp.";
     }
  if (x == -152 && y == 94) {
    s = FROSTMARCHES_TOWNS "keryth/room/wharf";
    long += " To the south likes the home of the Goden, the city of Keryth.";
  }
  if (x == -153 && y == 93) {
    e = FROSTMARCHES_TOWNS "keryth/room/wharf";
    long += " To the east likes the home of the Goden, the city of Keryth.";
  }
  if (x == -150 && y == 0) {
    n = BARIA_TOWNS "baria/room/path12";
    long += " The village of Baria lies to the north.";
  }
  
  /* The End of the World As We Know It */
  
  if (x == 500) e = OCEAN + "-500," + y;
  if (x == -500) w = OCEAN + "500," + y;
  if (y == 500) { 
  	n = 0;
  	long += " To the north, ice makes the ocean completely impassable.";
  	RemoveProperty("ocean");
  	SetProperty("coastal", 1);
  }
  if (y == -500) {
  	if (x > 1 || x < -1) {
  	  s = XANDRIA_VIRTUAL "desert/" + x + ",0";
  	  sw = 0;
  	  se = 0;
  	  long += " To the south, the ocean ends along a desert coastline.";
    }
    else {
      s = XANDRIA_VIRTUAL "river/" + x + ",0";
      sw = 0;
      se = 0;
      long += " To the south lies the delta to a large and deep river.";
    }
  }
  if (climate != "") SetClimate(climate); 
  SetLong(long);
  SetShort(short);
  SetListen("default", listen);
  SetSmell("default", smell);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
  if (ne) AddExit("northeast", ne);
  if (ISLANDS_D->GetNearbyIsland(x, y)) ISLANDS_D->ProcessIsland(this_object(), x, y);
  createShipEncounter(x, y);
}

int eventGenerateEncounter(string fcaptain, string fship) {
	object captain, ship;
  if (!fship) return;
  ship = new(fship);
  if (!ship) return;
  captain = new(fcaptain);
  if (!captain) {
    ship->eventDestruct();
    return;
  }
  // ship->eventMoveLiving("/domains/innersea/virtual/ocean/" + X + "," + Y);
  ship->eventMove(this_object());
  ship->ResetExit();
  ship->SetCaptain(captain->GetKeyName());
  captain->eventMove(ship);
  environment(this_player())->eventPrint(capitalize(ship->GetShort()) + " has moved within our sights!");
  CHAT_D->eventSendChannel("", "shipreports", "ENC @ " + X + "," + Y + ": " + fcaptain + " / " + this_player()->GetKeyName(), 1);
}	

void createShipEncounter(int x, int y) {
  object ship, captain;
  string fship = 0, fcaptain = 0;
  int level = this_player()->GetLevel();
  if (!sizeof(filter(all_inventory(environment(this_player())), (: userp :)))) return;
  
  /* Encounters by Haven Town */
  if (y < 50 && y > -50 && x < 50 && x > -50) {
    if (!random(200)) { eventGenerateEncounter(STD_NPC "elfcaptain",    STD_VEHICLES "warbird"); }
    if (!random(250)) { if (level > 25) eventGenerateEncounter(STD_NPC "handcaptain",   STD_VEHICLES "elvenwarship"); }
  }                                                           
  /* Encounters by Tairi */
  if (y > -750 && y < -250 && x > 200 && x < 400) {               
    if (!random(200)) { if (level > 25) eventGenerateEncounter(STD_NPC "wakocaptain",   STD_VEHICLES "taigalley"); }
    if (!random(100)) { eventGenerateEncounter(STD_NPC "taifisher", STD_VEHICLES "taifisher"); }
  }                        
  /* Encounters in the Western Sea */                                   
  if (x > -200 && x < -30 && y > -150 ) {                     
    if (!random(200)) { if (level > 25) eventGenerateEncounter(STD_NPC "godenviking",   STD_VEHICLES "longship"); }
    if (!random(250)) { if (level > 50) eventGenerateEncounter(STD_NPC "piratecaptain", STD_VEHICLES "warship"); }
  }
  /* Encounters near Parva/Havenwood */
  if (y > 0 && y < 120 && x > 0) {
    if (!random(200)) { if (level > 25) eventGenerateEncounter(STD_NPC "darkelfcaptain",STD_VEHICLES "caravel"); }
  }
  /* Merchant Captain can be anywhere */
  if (!random(200)) { eventGenerateEncounter(STD_NPC "merchantcaptain", STD_VEHICLES "merchantship"); }
}


/*  This is to stop a massive issue. Massive. */

void heart_beat() {
	::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (living(o)) return;
    if (o->GetOwner()) return;
  }
  counter++;
  if (counter > 3)
    eventDestruct();
}
