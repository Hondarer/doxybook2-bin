#pragma once
#include "Enums.hpp"
#include <string>

namespace Doxybook2 {
    struct Config {
        // What is the base URL to prepend all links with?
        std::string baseUrl{""};

        // What should the file end with?
        std::string fileExt{"md"};

        // Where to copy images
        std::string imagesFolder{"images"};

        // What should the link end with?
        std::string linkSuffix{".md"};

        // Name of the mainpage (indexpage)
        std::string mainPageName{"indexpage"};

        // Where to store the output files?
        std::string outputDir;

        // What are the folder names?
        std::string folderClassesName{"Classes"};
        std::string folderExamplesName{"Examples"};
        std::string folderFilesName{"Files"};
        std::string folderGroupsName{"Modules"};
        std::string folderNamespacesName{"Namespaces"};
        std::string folderRelatedPagesName{"Pages"};

        // Formulas (Latex)
        std::string formulaBlockEnd{"\\]"};
        std::string formulaBlockStart{"\\["};
        std::string formulaInlineEnd{"\\)"};
        std::string formulaInlineStart{"\\("};

        // What are the names of the index files?
        std::string indexClassesName{"index_classes"};
        std::string indexClassesTitle{"Classes"};
        std::string indexExamplesName{"index_examples"};
        std::string indexExamplesTitle{"Examples"};
        std::string indexFilesName{"index_files"};
        std::string indexFilesTitle{"Files"};
        std::string indexGroupsName{"index_groups"};
        std::string indexGroupsTitle{"Modules"};
        std::string indexNamespacesName{"index_namespaces"};
        std::string indexNamespacesTitle{"Namespaces"};
        std::string indexRelatedPagesName{"index_pages"};
        std::string indexRelatedPagesTitle{"Pages"};

        // What templates to use for each kind?
        std::string templateIndexClasses{"index_classes"};
        std::string templateIndexExamples{"index_examples"};
        std::string templateIndexFiles{"index_files"};
        std::string templateIndexGroups{"index_groups"};
        std::string templateIndexNamespaces{"index_namespaces"};
        std::string templateIndexRelatedPages{"index_pages"};
        std::string templateKindClass{"kind_class"};
        std::string templateKindDir{"kind_file"};
        std::string templateKindExample{"kind_page"};
        std::string templateKindFile{"kind_file"};
        std::string templateKindGroup{"kind_nonclass"};
        std::string templateKindInterface{"kind_class"};
        std::string templateKindJavaEnum{"kind_class"};
        std::string templateKindNamespace{"kind_nonclass"};
        std::string templateKindPage{"kind_page"};
        std::string templateKindStruct{"kind_class"};
        std::string templateKindUnion{"kind_class"};

        // Which source files are allowed to be included in the output? (empty => all)
        std::vector<std::string> filesFilter{};

        // Folder to generate.
        std::vector<FolderCategory> foldersToGenerate{
            FolderCategory::CLASSES,
            FolderCategory::EXAMPLES,
            FolderCategory::FILES,
            FolderCategory::MODULES,
            FolderCategory::NAMESPACES,
            FolderCategory::PAGES,
        };

        // Copy images from the Doxygen xml dir?
        bool copyImages{true};

        // Generate extra JSON for each rendered template
        bool debugTemplateJson{false};

        // Output links as HTML <a> tags and inline code as <code> tags instead of Markdown.
        bool linkAndInlineCodeAsHTML{false};

        // Convert all refids (including folder names) into lowercase?
        bool linkLowercase{false};

        // Should we put the class, namespace, modules, and files indexes
        // into their respective folders? (Hugo/Learn) needs that!
        bool indexInFolders{false};

        // If mainpage (indexpage) is present, should it be located
        // in the outputDir folder or in outpurDir/folderRelatedPagesName folder?
        bool mainPageInRoot{false};

        // Replace underscores with hyphens in anchors?
        bool replaceUnderscoresInAnchors{true};

        // Sort alphabetically
        bool sort{false};

        // Put all stuff into categorized folders or everything into destination folder?
        bool useFolders{true};
    };

    void loadConfig(Config& config, const std::string& path);
    void loadConfigData(Config& config, const std::string& src);
    void saveConfig(Config& config, const std::string& path);
} // namespace Doxybook2
