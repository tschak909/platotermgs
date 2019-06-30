PLATO_OBJS=obj/io.a \
	obj/marinetti.a \
	obj/keyboard.a \
	obj/main.a \
	obj/protocol.a \
	obj/screen.a \
	obj/terminal.a \
	obj/prompt.a \
	obj/touch.a

PLATO_OBJS_PREFIX=obj/io \
	obj/marinetti \
	obj/keyboard \
	obj/main \
	obj/protocol \
	obj/screen \
	obj/terminal \
	obj/prompt \
	obj/touch

all : plato dist

.PHONY: clean

clean:
	$(RM) obj/* dist/*

obj: 
	mkdir -p $@ dist

plato : $(PLATO_OBJS)
	iix -DKeepType=S16 link $(PLATO_OBJS_PREFIX) keep=dist/PLATOTERM#B30000
	rm -rf dist/plato.2mg
	cadius createvolume dist/plato.2mg PLATOTERM 800KB
	cadius addfile dist/plato.2mg PLATOTERM dist/PLATOTERM#B30000
	cadius addfile dist/plato.2mg PLATOTERM dist.files/COPYING
	cadius addfile dist/plato.2mg PLATOTERM dist.files/README
	cadius addfolder dist/plato.2mg PLATOTERM/Icons dist.files/Icons

obj/%.a : src/%.c
	iix $(ORCA_FLAGS) compile -I $< keep=$(@D)/$*
