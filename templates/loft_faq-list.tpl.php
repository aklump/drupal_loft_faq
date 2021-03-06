<?php
/**
 * @file
 * Template file for category listings
 *
 * $total_faqs int Total items in all categories.
 * $total_category_faqs Total items in this category or if not category is
 *   given, the same as total_faqs.
 * $total_fags_by_category array Totals by category keys.
 * $categories array All categories.
 * $anchor - the name attribute for the anchor tag; correlates with the toc.
 * $category - the santized category name.
 * $items - an array of renderable arrays holding the items.
 * $has_toc - bool if the toc is being displayed.
 * $wrapper_attributes - array
 * $title_display - string
 *   - none: Category will not print out as title
 *   - before
 *   - invisible
 *
 * @ingroup loft_faq
 * @{
 */
?>
<a name="<?php print $anchor ?>"></a>
<div<?php print drupal_attributes($wrapper_attributes) ?>>
  <?php if ($title_display == 'before') :?>
    <h2 class="view-title loft-faq-category"><?php print $category ?></h2>
  <?php endif; ?>
  <?php if ($title_display == 'invisible') :?>
    <label class="element-invisible view-title loft-faq-category"><?php print $category ?></label>
  <?php endif; ?>
  <dl class="loft-faq-category">
    <?php foreach ($items as $item) : ?>
      <?php print render($item) ?>
    <?php endforeach; ?>
  </dl><!-- /.loft-faq-content -->
  <?php if ($title_display == 'after') :?>
    <h2 class="view-title loft-faq-category"><?php print $category ?></h2>
  <?php endif; ?>
  <?php if ($total_faqs > 10 && $has_toc) :?>
    <a class="loft-faq-top" href="#loft-faq-toc"><?php print t('See Categories') ?></a>
  <?php endif; ?>
  <?php print render($theme_bottom) ?>
</div><!-- /.loft-faq-category-wrapper -->
