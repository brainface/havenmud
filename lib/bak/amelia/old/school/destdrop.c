void init() {
   ::init();
   if(!livingp(this_player())) {
      eventDestruct(this_player());
   }
}
