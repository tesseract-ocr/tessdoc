---
layout: page
permalink: /mypage/
title: My Page
---
{% capture my_include %}{% include_relative mypage_content.md %}{% endcapture %}
{{ my_include | markdownify }}
