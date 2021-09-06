// Copyright Peter Son, all rights reserved.

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {

    std::set<std::string> subcommands_flags;
    subcommands_flags.insert("--version");
    subcommands_flags.insert("-v");
    subcommands_flags.insert("--help");
    subcommands_flags.insert("-h");

    if (argc == 1 || (argv[1][0] == '-' && subcommands_flags.count(argv[1]) == 0)) {
        return main_docbox_porcelain(argc, argv);

    } else {
        std::string subcommand = argv[1];

        if (subcommand == "create") {
            return main_docbox_create(argc, argv);
        } else if (subcommand == "dump") {
            return main_docbox_dump(argc, argv);
        } else if (subcommand == "index-rebuild") {
            return main_docbox_index_rebuild(argc, argv);
        } else if (subcommand == "--version" || subcommand == "-v") {
            if (argc != 2) {
                printf("WARNING: Ignoring extra parameters after '%s'.", subcommand.c_str());
            }
            print_version_message();
            return 0;

        } else if (subcommand == "help" || subcommand == "-h" || subcommand == "--help") {

            if (argc == 2) {
                help_docbox_porcelain();
                return 0;
            } else if (argc == 3) {
                std::string subcommand2 = argv[2];
                if (subcommand2 == "create") {
                    help_docbox_create();
                    return 0;
                } else if (subcommand2 == "serve") {
                    help_docbox_serve();
                    return 0;
                } else if (subcommand2 == "dump") {
                    help_docbox_dump();
                } else if (subcommand2 == "restore") {
                    help_docbox_restore();
                } else if (subcommand2 == "index-rebuild") {
                    help_docbox_index_rebuild();
                } else {
                    printf("ERROR: No help for '%s'\n", subcommand2.c_str());
                    return 1;
                }

            } else {
                puts("ERROR: Too many parameters to 'docbox help'.  Try 'docbox help [subcommand]'.");
                return 1;
            }

        } else {
            printf("ERROR: Unrecognized subcommand '%s'. Try 'docbox help'.\n", subcommand.c_str());
            return 1;
        }
    }
}