JCC = javac
JFLAGS = -implicit:none -encoding UTF-8 -d bin -classpath bin

default: \
		bin/fr/sylarades/test/Main.class\
		bin/fr/sylarades/test/Coord.class

bin/fr/sylarades/test/Main.class: src/fr/sylarades/test/Main.java
	 $(JCC) $(JFLAGS) -sourcepath src src/fr/sylarades/test/Main.java
bin/fr/sylarades/test/Coord.class: src/fr/sylarades/test/Coord.java
	 $(JCC) $(JFLAGS) -sourcepath src src/fr/sylarades/test/Coord.java

jar:
	jar cvfe Bonbon.jar <classMain>  -C bin fr -C res

