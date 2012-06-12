<?php
/**
 * @file
 * Template file for category listings
 *
 * $anchor - the name attribute for the anchor tag; correlates with the toc
 * $category - the category name
 * $node
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{
 */
print render(node_view($node, 'teaser')) ?>
