package fr.sylarades.test;

public class Coord {
	int x;
	int y;
	public Coord(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public String toString(){
		return "("+x+","+y+")";
	}
}
