## SUMMARY
This module provides an FAQ content type (via Features), an FAQ view,
and the means to embed that view on a node.

## REQUIREMENTS
* It would be a good idea to install sort_views module (itls)

## INSTALLATION
* Download and unzip this module into your modules directory.
* Goto Administer > Site Building > Modules and enable this module.


## CONFIGURATION
* Add the NID of the page you want to use as your FAQ
* Select the node type to use; loft_faq is included in features
* Visit the manage display tab for that node type and place the fields in the correct order:
    1. FAQ: Category List
    1. FAQ: Questions
* Create some FAQ entities and visit the page listed above
* CSS style as needed


## ALTERNATE CONFIGURATION
* To have multiple FAQ pages take a look at hook_loft_faq_node_append.

## Configuration with Views
* A view is provided by default with the machine name `loft_faq`.
* You should not edit the _Format_ section, leave as is.
* Ok to edit most other sections including: _Filters, Sort, Title_, Etc.
* The display _Core_ is used by the module to generate pages, so be especially careful with this display.

## Blocks
* A block is available that uses the faq templates by way of `loft_faq_preprocess_views_view`.  Using this block is encouraged as it will leverage the tpl files and you will not have to write any css or theme template files.
* If you need another block just create a new Block display on the view; as long as the display is a block on the view `loft_faq`, it will receive the same automatic formatting using the faq templates.

## DEVELOPERS
* Take a look at `loft_faq.api.php` for advanced config.


## USAGE
* When the designated page is loaded, the FAQ index and view will be appended to
  the page.


## CONTACT
* **In the Loft Studios**
* Aaron Klump - Developer
* PO Box 29294 Bellingham, WA 98228-1294
* _aim_: theloft101
* _skype_: intheloftstudios
* _d.o_: aklump
* <http://www.InTheLoftStudios.com>