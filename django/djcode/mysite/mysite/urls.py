from django.conf.urls import patterns, include, url
from django.contrib import admin

from mysite.views import hello
from mysite.timeViews import current_datetime
from mysite.books import views
from mysite import login



# urlpatterns = patterns('',
#     # Examples:
#     # url(r'^$', 'mysite.views.home', name='home'),
#     # url(r'^blog/', include('blog.urls')),

#     url(r'^admin/', include(admin.site.urls)),
# )

urlpatterns = patterns('',
        ('^hello/$', hello),
        ('^time/$', current_datetime),
        url(r'^admin/', include(admin.site.urls)),
        url(r'^$', hello),
        url(r'^request_meta/$', views.request_meta),
        url(r'^search_form/$', views.search_form),
        url(r'^search/$', views.search),
        )

urlpatterns += patterns('',
        url(r'^about/', include('mysite.login.urls')),
        )
