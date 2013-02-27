<?php
/**
 * @file
 * Template file for category listings
 *
 * $anchor - the name attribute for the anchor tag; correlates with the toc
 * $category - the santized category name
 * $items - an array of renderable arrays holding the items
 * $has_toc - bool if the toc is being displayed
 * $attributes - array
 *
 * @ingroup loft_faq Frequently Asked Questions
 * @{
 */
?>
<a name="<?php print $anchor ?>"></a>
<div <?php print drupal_attributes($wrapper_attributes) ?>>
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
  <?php if ($has_toc) :?>
    <a class="loft-faq-top" href="#loft-faq-toc"><?php print t('Back to Index') ?></a>
  <?php endif; ?>

</div><!-- /.loft-faq-category-wrapper -->
