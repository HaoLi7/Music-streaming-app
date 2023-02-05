objects = main.o View.o Controller.o Songify.o MediaFactory.o Criteria.o Album.o Song.o A_Criteria.o C_Criteria.o AorC_Criteria.o

app: $(objects)
	g++ -o app $(objects)

main.o: Controller.h main.cc
	g++ -c main.cc 

View.o: Album.h View.h View.cc 
	g++ -c View.cc

Controller.o: Songify.h View.h MediaFactory.h Controller.h Controller.cc 
	g++ -c Controller.cc


Songify.o: MediaFactory.h Album.h Songify.h Songify.cc
	g++ -c Songify.cc

MediaFactory.o: Album.h AorC_Criteria.h MediaFactory.h MediaFactory.cc
	g++ -c MediaFactory.cc

A_Criteria.o: Criteria.h A_Criteria.h A_Criteria.cc
	g++ -c A_Criteria.cc

C_Criteria.o: Criteria.h C_Criteria.h C_Criteria.cc
	g++ -c C_Criteria.cc

AorC_Criteria.o: A_Criteria.h C_Criteria.h AorC_Criteria.h AorC_Criteria.cc
	g++ -c AorC_Criteria.cc

Criteria.o: Song.h Criteria.cc Criteria.h
	g++ -c Criteria.cc

Album.o: Song.h Array.h Album.cc Album.h
	g++ -c Album.cc
	
Song.o: Song.cc Song.h 
	g++ -c Song.cc

clean:
	rm -f app *.o	