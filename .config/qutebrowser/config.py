#
# ~/.config/qutebrowser/config.py
#

c.content.user_stylesheets = ['user.css']

config.load_autoconfig(False)

c.confirm_quit = ["downloads"]

c.auto_save.session = True

c.colors.webpage.darkmode.enabled = False
c.colors.webpage.preferred_color_scheme = 'dark'

c.editor.command = ['st', '-e', 'vim', '-p', '{}' ]

c.input.insert_mode.auto_leave = True
c.input.insert_mode.auto_load = True

c.scrolling.smooth = False

c.window.hide_decoration = True

c.tabs.position = "top"
c.tabs.show = "always"
c.tabs.background = True
c.tabs.select_on_remove = "last-used"
c.tabs.mousewheel_switching = False

c.hints.uppercase = True
c.hints.leave_on_load = False

c.content.blocking.enabled = True
c.content.blocking.method = "both"
c.content.fullscreen.overlay_timeout = 666
c.content.geolocation = False
c.content.autoplay = False
c.content.default_encoding = 'utf-8'
c.content.pdfjs = True
c.content.cookies.accept = "never"
c.content.javascript.enabled = False
c.content.notifications.enabled = False

c.url.default_page = "about:blank"
c.url.start_pages = ["about:blank"]
c.url.open_base_url = True

sites = [
    'proton.me',
    'github.com',
    'gitlab.com',
    'foli.fi',
    ]
for site in sites:
    config.set('content.javascript.enabled', True, site)
    config.set('content.cookies.accept', 'no-3rdparty', site)

config.set('content.headers.user_agent', 'iPhone', 'docs.google.com')
config.set('content.headers.user_agent', 'iPhone', 'drive.google.com')

config.source('rose-pine.py') # ~/.config/qutebrowser/rose-pine.py
config.source('bindings.py')  # ~/.config/qutebrowser/bindings.py
config.source('search.py')    # ~/.config/qutebrowser/search.py
config.source('adblock.py')   # ~/.config/qutebrowser/adblock.py

