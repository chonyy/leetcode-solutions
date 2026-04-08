/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */
class Solution {
    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        String hostname = getHostname(startUrl);
        Set<String> visited = ConcurrentHashMap.newKeySet();
        BlockingQueue<String> queue = new LinkedBlockingQueue<>();
        AtomicInteger pending = new AtomicInteger(1);
        ExecutorService executor = Executors.newFixedThreadPool(8);

        visited.add(startUrl);
        queue.add(startUrl);

        while (pending.get() > 0) {
            try {
                String url = queue.poll(50, TimeUnit.MILLISECONDS);
                if (url == null) continue;
                executor.submit(new CrawlTask(url, hostname, htmlParser, visited, queue, pending));
            } catch (InterruptedException e) {
                break;
            }
        }

        executor.shutdown();
        return new ArrayList<>(visited);
    }

    private String getHostname(String url) {
        int start = url.indexOf("//") + 2;
        int end = url.indexOf('/', start);
        return end == -1 ? url.substring(start) : url.substring(start, end);
    }
}

class CrawlTask implements Runnable {
    private final String url;
    private final String hostname;
    private final HtmlParser htmlParser;
    private final Set<String> visited;
    private final BlockingQueue<String> queue;
    private final AtomicInteger pending;

    CrawlTask(String url, String hostname, HtmlParser htmlParser,
              Set<String> visited, BlockingQueue<String> queue, AtomicInteger pending) {
        this.url = url;
        this.hostname = hostname;
        this.htmlParser = htmlParser;
        this.visited = visited;
        this.queue = queue;
        this.pending = pending;
    }

    @Override
    public void run() {
        try {
            for (String next : htmlParser.getUrls(url)) {
                if (getHostname(next).equals(hostname) && visited.add(next)) {
                    pending.incrementAndGet();
                    queue.add(next);
                }
            }
        } finally {
            pending.decrementAndGet();
        }
    }

    private String getHostname(String url) {
        int start = url.indexOf("//") + 2;
        int end = url.indexOf('/', start);
        return end == -1 ? url.substring(start) : url.substring(start, end);
    }
}