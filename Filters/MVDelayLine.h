#ifndef DELAYLINE_H
#define	DELAYLINE_H

class DelayLine {
public:
	DelayLine();
	~DelayLine();
	void create(int);
	void push(float);
	float get(void);
	void clear(void);
private:
	float *line;
	int ptr;
	int del;
};

#endif	/* DELAYLINE_H */
