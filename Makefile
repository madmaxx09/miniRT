NAME			:= miniRT

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -O3
DEPFLAGS     	 = -MT $@ -MMD -MP -MF $(DDIR)/$*.d

VPATH			:= src/ src/graphic/ src/math/ src/parse/ src/print/ src/trace/
SRCS			:= main.c store_data.c store_more.c store_utils.c array_to_double.c parse.c custom_malloc.c mlx_press.c raytrace.c \
					vec_math.c rgb_math.c more_math.c viewport.c random.c obj_inter.c pdf.c denoising.c hit_box.c assign_print.c \
					intersection_utils.c math.c math2.c rgb_math2.c add_obj.c

ODIR			:= obj
OBJS			:= $(SRCS:%.c=$(ODIR)/%.o)

DDIR			:= $(ODIR)/.deps
DEPS			:= $(SRCS:%.c=$(DDIR)/%.d)

LIBS			:= libft/libft.a libmlx/libmlx42.a
LDLIBS          := $(LIBS) -lm -lpthread
LDFLAGS         :=


UNAME	:= $(shell uname -s)
NUMPROC	:= 8

ifeq ($(UNAME), Linux)
    NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
	CFLAGS	+= -D LINUX -D THREADS=$(NUMPROC) -Wno-unused-result
	LDLIBS	+= -lglfw -ldl
else ifeq ($(UNAME), Darwin)
    NUMPROC := $(shell sysctl -n hw.ncpu)
	CFLAGS	+= -D DARWIN -D THREADS=$(NUMPROC)
	LDLIBS += libmlx/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
endif


all:
	@$(MAKE) $(NAME) -j$(NUMPROC)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

$(ODIR)/%.o: %.c $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I./src -I./lib -c $< -o $@

$(ODIR):
	@mkdir -p $@

$(DDIR):
	@mkdir -p $@

%.a:
	@$(MAKE) -C $(dir $@)

clean:
	@$(MAKE) -C libft fclean
	@$(MAKE) -C libmlx fclean
	$(RM) -r $(DDIR) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

$(DEPS):
include $(wildcard $(DEPS))