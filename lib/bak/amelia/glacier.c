#include <lib.h>
inherit LIB_ROOM;

#define GLACIER "/domains/test/virtual/glacier/"
mapping Intersections = ([ ]);
string GetIntersection(string thisroom, string otherroom);
string MakeIntersection(string thisroom, string otherroom);
int SetUpStartingIntersections();

static void create(int x, int y) {
	string long;
	string thisroom = GLACIER + x + "," + y;
	string n, ne, e, se, s, sw, w, nw;
	string array GlacierExits = ({ });
	string array CrevassExits = ({ });
	string array IceBridgeExits = ({ });
	::create();
	if (Intersections == ([ ]) ){ SetUpStartingIntersections(); }
	SetShort("on the Yunpti Glacier");
	long = "The Yunpti Glacier surrounds this area.";
	if( x < 20 ) {
		e = GLACIER + (x+1) + "," + y;
	}
	if(x > 0) {
		w = GLACIER + (x-1) + "," + y;
	}
	if(y < 20) {
		n = GLACIER + x + "," + (y+1);
	}
	if(y > 0 ) {
		s = GLACIER + x + "," + (y-1);
	}
	foreach(array go in ({ ({ n,"north" }),({ e,"east" }), ({ w,"west" }),
				({ s,"south" }) })) {
		if(go[0]) {
			if(!GetIntersection(thisroom,go[0])) {
				MakeIntersection(thisroom,go[0]);
			}
			switch(GetIntersection(thisroom,go[0])) {
				case "glacier":
				GlacierExits += ({ go[1] });
				break;
				case "crevass":
				CrevassExits += ({ go[1] });
				break;
				case "ice bridge":
				IceBridgeExits += ({ go[1] });
				CrevassExits += ({ go[1] });
				break;
			}
		}
	}
	foreach(string goa in CrevassExits) {
		if(member_array(goa, IceBridgeExits) == -1) {
			switch(goa) {
				case "north":
				n = 0;	
				break;
				case "east":
				e = 0;
				break;
				case "south":
				s = 0;
				break;
				case "west":
				w = 0;
				break;
			}
		}
	}
	if(!sizeof(GlacierExits)) {
		long+= "  The entire area is surrounded by crevasses.";
	}
	else if(sizeof(GlacierExits) == 1) {
		long+= "  The glacier is unbroken to the " + GlacierExits[0] + ".";
	}
	else {
		long+= "  The glacier is unbroken to the ";
		while(sizeof(GlacierExits) > 1) {
			long+= GlacierExits[0] + ", ";
			GlacierExits -= ({ GlacierExits[0] });
		}
		long += "and " + GlacierExits[0] + ".";
	}
	if(sizeof(GlacierExits)) {
		if(sizeof(CrevassExits) == 1) {
			long +="  A crevass interrupts the smooth flow of the "
			"glacier to the " + CrevassExits[0] + ".";
			if(member_array(CrevassExits[0],IceBridgeExits) != -1) {
				long+="  An ice bridge crosses the " + CrevassExits[0] +
					"ern crevass.";
			}
		}
		else if(!sizeof(CrevassExits) ) {
		}
		else {
			while(sizeof(CrevassExits) > 1) {
				long +="  A crevass interrupts the smooth flow of the "
				"glacier to the " + CrevassExits[0] + ".";
				if(member_array(CrevassExits[0],IceBridgeExits) != -1) {
					long+="  An ice bridge crosses the " + CrevassExits[0] +
						"ern crevass.";
				}
				CrevassExits -= ({ CrevassExits[0] });
			}
			long += "  A crevass interrupts the smooth flow of the "
				"glacier to the " + CrevassExits[0] + ".";
			if(member_array(CrevassExits[0],IceBridgeExits) != -1) {
				long+="  An ice bridge crosses the " + CrevassExits[0] +
					"ern crevass.";
			}
		}
	}
	SetLong(long);
	if(n && n!= "") AddExit("north",n);
	if(e && e!= "") AddExit("east",e);
	if(w && w!= "") AddExit("west",w);
	if(s && s!= "") AddExit("south",s);
}

string GetIntersection(string thisroom, string thatroom) {
	if(member_array((( thisroom + thatroom )),keys(Intersections))!= -1) {
		return Intersections[(thisroom+thatroom)];
	}
        if(member_array((( thatroom+thisroom )),keys(Intersections)) != -1) {
		return Intersections[(thatroom+thisroom)];
	}
	return 0;
}

string MakeIntersection(string thisroom, string thatroom) {
	switch(random(6)+1) {
		case 1..3:
		Intersections += ([ ( thisroom+thatroom ) : "glacier" ]);
		break;
		case 4..5:
		Intersections += ([ ( thisroom + thatroom ) : "crevass" ]);
		break;
		case 6:
		Intersections += ([ ( thisroom + thatroom ) : "ice bridge" ]);
		break;
	}
	return GetIntersection(thisroom, thatroom);
}

int SetUpStartingIntersections() {
	int x, y;
	string whatsit = "crevass";
	x = 10;
	for(y=0;y<21;y++) {
		if(random(10)) {
			whatsit = "ice bridge";
		}
		Intersections += ([ ({ GLACIER + x + "," + y, 
					GLACIER + (x-1) + "," + y }) :
					whatsit, ]);
		whatsit = "crevass";
	}
	return 1;
}
