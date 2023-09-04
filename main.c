#include <stdio.h>
#include <stdbool.h>
#include <argp.h>

#include "config.h"

#include <SDL.h>

const char *argp_program_version = PACKAGE_STRING;
const char *argp_program_bug_address = PACKAGE_BUGREPORT;

static char doc[] = "helloworld - argp test program";

// static char args_doc[] = "ARG1 ARG2";

static struct argp_option options[] = {
        {"verbose", 'v', 0, 0, "Produce verbose output"},
        {"floppy-image", 'f', "FILE", 0, "Floppy image file"},
        {"hdd-image", 'h', "FILE", 0, "HDD image file"},
        {0}
};

struct arguments {
//        char *args[2];
        bool verbose;
        char *f_image;
        char *h_image;
};

static struct arguments cmd_args;;

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
        struct arguments *arguments = &cmd_args;
        switch (key) {
        case 'v':
                arguments->verbose = true;
                break;
        case 'f':
                arguments->f_image = arg;
                break;
        case 'h':
                arguments->h_image = arg;
                break;
        case ARGP_KEY_ARG:
//                if (state->arg_num >= 2) {
                if (state->arg_num > 0) {
                        argp_usage(state);
                }

//                arguments->args[state->arg_num] = arg;
                break;
        case ARGP_KEY_END:
/*                if (state->arg_num < 2) {
                        argp_usage(state);
                } */
                if (!arguments->f_image && !arguments->h_image) {
                        printf("Specify at least one image file.\n");
                        argp_usage(state);
                }
                break;
        default:
                return ARGP_ERR_UNKNOWN;
        }
        return 0;
}


// static struct argp argp = { options, parse_opt, args_doc, doc };
static struct argp argp = { options, parse_opt, NULL, doc };



int parse_options(int argc, char **argv)
{
        cmd_args.verbose = false;
        cmd_args.h_image = NULL;
        cmd_args.f_image = NULL;
        argp_parse(&argp, argc, argv, 0, 0, &cmd_args);

        if (cmd_args.f_image) {
                printf("Floppy-image: %s\n", cmd_args.f_image);
        }
        if (cmd_args.h_image) {
                printf("HDD-image: %s\n", cmd_args.h_image);
        }

        exit(0);
        return 0;
}


int main(int argc, char **argv)
{
        (void)parse_options(argc, argv);

        SDL_Window *screen = SDL_CreateWindow("blah", 0, 0, 320, 200,
                                              SDL_WINDOW_SHOWN);
        if (!screen) {
                return -1;
        }

        SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1,
                        SDL_RENDERER_ACCELERATED);
        if (!renderer) {
                return -1;
        }
        atexit(SDL_Quit);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        bool quit = false;
        while (!quit) {
                SDL_RenderPresent(renderer);
                SDL_Event event;
                if (SDL_WaitEventTimeout(NULL, 10)) {
                        while (SDL_PollEvent(&event)) {
                                switch (event.type) {
                                case SDL_QUIT:
                                        quit = true;
                                        break;
                                default:
                                        break;
                                }
                        }
                }
        }

#ifdef CONFIG_FLOPPY_SOUND
        printf("Floppy seek sound enabled\n");
#endif
        printf("Hello world\n");
        return 0;
}
