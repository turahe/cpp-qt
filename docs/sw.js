// Service Worker for C++ dan Qt Programming Guide
// Provides offline support and caching

const CACHE_NAME = 'cpp-qt-guide-v1';
const urlsToCache = [
  '/',
  '/index.html',
  '/assets/style.css',
  '/assets/script.js',
  '/manuscript/book.md',
  '/manuscript/README.md',
  '/manuscript/00-prakata.md',
  '/manuscript/01-pengenalan.md',
  '/manuscript/02-tipedata.md',
  '/manuscript/02-control-statement.md',
  '/manuscript/03-array-string.md',
  '/manuscript/04-fuction.md',
  '/manuscript/05-pointer-referensi.md',
  '/manuscript/06-class-object.md',
  '/manuscript/06-debugging.md',
  '/manuscript/07-turunan.md',
  '/manuscript/08-operator.md',
  '/manuscript/09-Polymorphism.md',
  '/manuscript/10-casting-database.md',
  '/manuscript/11-design-patterns.md',
  '/manuscript/11-library.md',
  '/manuscript/12-file-stream-xml.md',
  '/manuscript/13-qt-webkit.md',
  '/manuscript/14-gui.md',
  '/manuscript/contoh.md',
  '/manuscript/daftar-pustaka.md',
  '/manuscript/00-about-authors.md',
  'https://cdn.tailwindcss.com',
  'https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&family=JetBrains+Mono:wght@300;400;500;600&display=swap'
];

// Install event
self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(CACHE_NAME)
      .then(cache => {
        console.log('Opened cache');
        return cache.addAll(urlsToCache);
      })
      .catch(error => {
        console.log('Cache install failed:', error);
      })
  );
});

// Fetch event
self.addEventListener('fetch', event => {
  event.respondWith(
    caches.match(event.request)
      .then(response => {
        // Return cached version or fetch from network
        if (response) {
          return response;
        }
        
        return fetch(event.request)
          .then(response => {
            // Check if we received a valid response
            if (!response || response.status !== 200 || response.type !== 'basic') {
              return response;
            }
            
            // Clone the response
            const responseToCache = response.clone();
            
            caches.open(CACHE_NAME)
              .then(cache => {
                cache.put(event.request, responseToCache);
              });
            
            return response;
          })
          .catch(() => {
            // Return offline page for navigation requests
            if (event.request.mode === 'navigate') {
              return caches.match('/offline.html');
            }
          });
      })
  );
});

// Activate event
self.addEventListener('activate', event => {
  event.waitUntil(
    caches.keys().then(cacheNames => {
      return Promise.all(
        cacheNames.map(cacheName => {
          if (cacheName !== CACHE_NAME) {
            console.log('Deleting old cache:', cacheName);
            return caches.delete(cacheName);
          }
        })
      );
    })
  );
});

// Background sync
self.addEventListener('sync', event => {
  if (event.tag === 'background-sync') {
    event.waitUntil(doBackgroundSync());
  }
});

// Push notification
self.addEventListener('push', event => {
  const options = {
    body: event.data ? event.data.text() : 'C++ dan Qt Programming Guide',
    icon: '/assets/icon-192x192.png',
    badge: '/assets/badge-72x72.png',
    vibrate: [100, 50, 100],
    data: {
      dateOfArrival: Date.now(),
      primaryKey: 1
    },
    actions: [
      {
        action: 'explore',
        title: 'Baca Buku',
        icon: '/assets/icon-192x192.png'
      },
      {
        action: 'close',
        title: 'Tutup',
        icon: '/assets/icon-192x192.png'
      }
    ]
  };
  
  event.waitUntil(
    self.registration.showNotification('C++ dan Qt Programming Guide', options)
  );
});

// Notification click
self.addEventListener('notificationclick', event => {
  event.notification.close();
  
  if (event.action === 'explore') {
    event.waitUntil(
      clients.openWindow('/')
    );
  }
});

// Background sync function
function doBackgroundSync() {
  // Implement background sync logic here
  console.log('Background sync completed');
}

// Message handling
self.addEventListener('message', event => {
  if (event.data && event.data.type === 'SKIP_WAITING') {
    self.skipWaiting();
  }
});

// Error handling
self.addEventListener('error', event => {
  console.error('Service Worker error:', event.error);
});

// Unhandled rejection
self.addEventListener('unhandledrejection', event => {
  console.error('Service Worker unhandled rejection:', event.reason);
}); 