JCC = javac
JFLAGS = -implicit:none -encoding UTF-8 -d bin -classpath bin

default: \
		bin/fr/sylarades/test/Main.class\
		bin/fr/sylarades/test/Location.class\
		bin/fr/yohan/test2/Coord.class

bin/fr/sylarades/test/Main.class: src/fr/sylarades/test/Main.java
	 $(JCC) $(JFLAGS) -sourcepath src src/fr/sylarades/test/Main.java
bin/fr/sylarades/test/Location.class: src/fr/sylarades/test/Location.java
	 $(JCC) $(JFLAGS) -sourcepath src src/fr/sylarades/test/Location.java
bin/fr/yohan/test2/Coord.class: src/fr/yohan/test2/Coord.java
	 $(JCC) $(JFLAGS) -sourcepath src src/fr/yohan/test2/Coord.java

jar:
	jar cvfe salut.jar <classMain>  -C bin fr -C res

jbrard@aramis.fr
jbrard@aramis.fr
jbrard@aramis.fr
jbrard@aramis.fr
jbrard@aramis.fr
jbrard@aramis.fr
jbrard@aramis.fr
jbrard@aramis.fr
