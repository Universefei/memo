from django.shortcuts import render
from django.shortcuts import render_to_response
from django.http import HttpResponse
from pprint import pprint

# Create your views here.


def request_meta(request):
    # ----------------------------------------------------------------------- #
    # BAD
    # ----------------------------------------------------------------------- #
    # ua = request.META['HTTP_USER_AGENT']

    # ----------------------------------------------------------------------- #
    # GOOD (version 1)
    # ----------------------------------------------------------------------- #
    # try:
    #     ua = request.META['HTTP_USER_AGENT']
    # except KeyError:
    #     ua = 'unknown'

    # ----------------------------------------------------------------------- #
    # GOOD (version 2)
    # ----------------------------------------------------------------------- #
    # referer = request.META.get('HTTP_USER_AGENT')
    referer = request.META.get('REMOTE_ADDR')
    # request.META.get('REFERER')
    # pprint(request.META)

    metadata = request.META
    html = []
    for k,v in metadata.items():
        html.append('<tr><td>%s</td><td>%s</td></tr>' % (k, v))
    return HttpResponse(html)


def search_form(request):
    return render_to_response("search_form.html")


def search(request):
    if 'q' in request.GET and request.GET['q']:
        message = 'You searched for: %r' % request.GET['q']
        return HttpResponse(message)
    else:
        message = 'You submitted an empty form.'
        return render_to_response("search_form.html", {'error': True})
