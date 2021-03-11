JCC = javac
JFLAGS = -implicit:none -encoding UTF-8 -d bin -classpath bin

default: \
		bin/fr/yohan/test/Main.class

bin/fr/yohan/test/Main.class: src/fr/yohan/test/Main.java
	 $(JCC) $(JFLAGS) -sourcepath src src/fr/yohan/test/Main.java

jar:
	jar cvfe samut.jar <classMain>  -C bin fr -C res

